#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "person.h"
#include "world.h"

#define BADCHANCE 3
#define BADEVENTS 5


static int go;
void checkPos(Person*, World*);
void commitMovement(Person*, World*);
void scoreboard(Person*);
void die(Person*, World*);

void scoreboard(Person* p) {
  printf("\nStrength: %d\tIntelligence: %d\nBoredom: %d\tCoffees: %d\nAnger: %d\tHats: %d\nHealth: %d\tMoney: $%d", p->getStrength(), p->getIntelligence(), p->getBoredom(), p->getCoffeesDrank(), p->getAnger(), p->getHatCount(), p->getHealth(), p->getMoney());
}


/*
* controls map switching
* when Person p hits given spot: switch
* switch represents current lvl, 0 offset
*/
void checkPos(Person* p, World* w) {
  switch(w->getCurrentLvl()) {
    case(0):
      if(p->getX() == 1 && p->getY() == 20) {
        w->changeWorld(1);
        p->move(19 - p->getX(), 13 - p->getY());
      }
      if(p->getX() == 3 && p->getY() == 9) {
        w->changeWorld(2);
        p->move(10 - p->getX(), 20 - p->getY());
      }
      if(p->getX() == 4 && p->getY() == 14) {
        w->changeWorld(3);
        p->move(5 - p->getX(), 7 - p->getY());
      }
      if(p->getX() == 6 && p->getY() == 16) {
        w->changeWorld(3);
        p->move(16 - p->getX(), 15 - p->getY());
      }
      if(p->getX() == 14 && p->getY() == 4) {
        w->changeWorld(4);
        p->move(14 - p->getX(), 16 - p->getY());
      }
      if(p->getX() == 11 && p->getY() == 3) {
        w->changeWorld(4);
        p->move(7 - p->getX(), 6 - p->getY());
      }
      if(p->getX() == 3 && p->getY() == 3) {
        w->changeWorld(5);
        p->move(17 - p->getX(), 19 - p->getY());
      }
      break;
    case(1):
      if(p->getX() == 20 && p->getY() == 13) {
        w->changeWorld(0);
        p->move(3 - p->getX(), 20 - p->getY());
      }
      break;
    case(2):
      if(p->getX() == 10 && p->getY() == 20) {
        w->changeWorld(0);
        p->move(3 - p->getX(), 11 - p->getY());
      }
      break;
    case(3):
      if(p->getX() == 5 && p->getY() == 6) {
        w->changeWorld(0);
        p->move(4 - p->getX(), 12 - p->getY());
      }
      if(p->getX() == 16 && p->getY() == 15) {
        w->changeWorld(0);
        p->move(6 - p->getX(), 18 - p->getY());
      }
      break;
    case(4):
      if(p->getX() == 7 && p->getY() == 5) {
        w->changeWorld(0);
        p->move(11 - p->getX(), 1 - p->getY());
      }
      if(p->getX() == 14 && p->getY() == 16) {
        w->changeWorld(0);
        p->move(14 - p->getX(), 6 - p->getY());
      }
      break;
      
    case(5):
      if(p->getX() == 17 && p->getY() == 19) {
        w->changeWorld(0);
        p->move(3 - p->getX(), 5 - p->getY());
      }
      break;
      
    case(6):
      if(p->getX() == 7 && p->getY() == 5) {
        w->changeWorld(0);
        p->move(11 - p->getX(), 1 - p->getY());
      }
      break;
      
    default:
      break;
  }
  w->printlvl(p->getX(), p->getY());
  std::cout << p->getX() << ' ' << p->getY() << std::endl;
  std::cout << "map: " << w->getCurrentLvl();
}

void die(Person* p, World* w) {
  p->move(20 - p->getX(), 17 - p->getY());
  w->changeWorld(666);
  go = 0;
}

void commitMovement(Person* p, World* w) {
  int hit;
  hit = w->evalPos(p->getX(), p->getY());
  int scenerioBit = 0;
  char* msgs[] = {
    "",
    "\nYou got mugged",
    "\nYou spilled your coffee",
    "\nA stranger assaults you",
    "\nA wild dog bites you"
    };
  switch(hit) {
    case 0:
      srand(time(NULL));
      if(rand() % BADCHANCE == 0) {
        srand(rand());
        switch(rand() % BADEVENTS) {
          case 0:
          case 1:
            system("cls");
            std::cout << "You're being mugged! What do you want to do?\n1. Cry and beg for mercy.\n2. Fight\n3. Run\n>>> ";
            int i;
            std::cin >> i;
            switch(i) { // eval user input for mugging scenerio
              case 2:
                std::cout << "\n...obviously you lose the fight...\nThey beat you more for making them work for it." << std::endl;
                scenerioBit = 1;
                p->setMoney(-1000);
                if(!p->setHealth(-55)){
                  die(p, w);
                }
                p->setAnger(70);
                break;
              case 3:
                std::cout << "\n...obviously they catch you...\nThey beat you even more for making them run; no one likes to run." << std::endl;
                scenerioBit = 1;
                p->setMoney(-1000);
                if(!p->setHealth(-75)){
                  die(p, w);
                }
                p->setAnger(80);
                break;
              case 1:
              default:
                std::cout << "\nThey feel bad seeing a grown adult cry so they barely beat you up." << std::endl;
                scenerioBit = 1;
                p->setMoney(-1000);
                if(!p->setHealth(-5)){
                  die(p, w);
                }
                p->setAnger(50);
                break;
            }
            break;
          case 2:
            scenerioBit = 2;
            p->setAnger(25);
            p->setCoffeesDrank(-1);
            break;
          case 3:
            scenerioBit = 3;
            if(!p->setHealth(-20)) {
              die(p, w);
            }
            p->setAnger(35);
            break;
          case 4:
            scenerioBit = 4;
            if(!p->setHealth(-20)) {
              die(p, w);
            }
            p->setAnger(45);
            break;
          default:
            break;
        }
      }
      break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 1: // ive hit a wall, move back the opposite direction by -1 * previous move
      switch(p->getDirection()) {
        case(0):           
          p->move(0, 1);
          break;
        case(1):           
          p->move(-1, 0);
          break;
        case(2):
          p->move(0, -1);
          break;
        case(3):
          p->move(1, 0);
          break;
      }
      break;
    case 7:
      p->setCoffeesDrank(1);
      w->remove(p->getX(), p->getY(), 6);
      break;
    case 3:
      if(!p->setCoffeesDrank(1)) {
        die(p, w);
      }
      w->remove(p->getX(), p->getY(), 0);
      break;
    case 8:
      p->setMoney(1);
      w->remove(p->getX(), p->getY(), 6);
      break;
    case 4:
      p->setMoney(1);
      w->remove(p->getX(), p->getY(), 0);
      break;
    case 9:
      p->setAnger(25);
      w->remove(p->getX(), p->getY(), 6);
      break;
    case 5:
      p->setAnger(25);
      w->remove(p->getX(), p->getY(), 0);
      break;
    case 14:
      p->setHatCount(1);
      w->remove(p->getX(), p->getY(), 0);
      break;
    default:
      break;
  }
  checkPos(p, w);
  std::cout << *(msgs + scenerioBit) << std::endl; // event selected with sceneriobit
  scoreboard(p);
}

int main(void) {
  Person* p = new Person();
  World* w = new World();
  int hit;
  char userIn;
  go = 1;
  w->printlvl(p->getX(), p->getY());
  while(go) {
    if(_kbhit()) {
      system("cls"); //windows specific :(
      switch(_getch()) {
        case 'w':
          p->move(0, -1);
          p->setDirection(0);
          break;
        case 'd':
          p->move(1, 0);
          p->setDirection(1);
          break;
        case 's':
          p->move(0, 1);
          p->setDirection(2);
          break;
        case 'a':
          p->move(-1, 0);
          p->setDirection(3);
          break;
        case 'q':
          go = 0;
          break;
        default:
          w->printlvl(p->getX(), p->getY());
          break;
      }
      commitMovement(p, w);
    }
  }
  delete(p);
  delete(w);
  return 1;
}