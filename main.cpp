#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "person.h"
#include "world.h"

void checkPos(Person*, World*);
void commitMovement(Person*, World*);
void scoreboard(Person*);

void scoreboard(Person* p) {
  printf("\nBoredom: %d\tCoffees: %d\nAnger: %d\tHats: %d\nHealth: %d\tMoney: $%d", p->getBoredom(), p->getCoffeesDrank(), p->getAnger(), p->getHatCount(), p->getHealth(), p->getMoney());
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
}


void commitMovement(Person* p, World* w) {
  int hit;
  hit = w->evalPos(p->getX(), p->getY());
  switch(hit) {
    case 0:
      srand(time(NULL));
      if(rand() % 3 == 0) {
        printf("something bad happens");
      }
      break;
    case 1:
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
      p->setCoffeesDrank(1);
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
    default:
      break;
  }
}

int main(void) {
  Person* p = new Person();
  World* w = new World();
  int go, hit;
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
          commitMovement(p, w);
          checkPos(p, w);
          // w->printlvl(p->getX(), p->getY());
          w->printlvl(p->getX(), p->getY());
          std::cout << p->getX() << ' ' << p->getY();
          scoreboard(p);
          break;
        case 'd':
          p->move(1, 0);
          p->setDirection(1);
          commitMovement(p, w);
          checkPos(p, w);
          // w->printlvl(p->getX(), p->getY());
          std::cout << p->getX() << ' ' << p->getY();
          scoreboard(p);
          break;
        case 's':
          p->move(0, 1);
          p->setDirection(2);
          commitMovement(p, w);
          checkPos(p, w);
          // w->printlvl(p->getX(), p->getY());
          std::cout << p->getX() << ' ' << p->getY();
          scoreboard(p);
          break;
        case 'a':
          p->move(-1, 0);
          p->setDirection(3);
          commitMovement(p, w);
          checkPos(p, w);
          // w->printlvl(p->getX(), p->getY());
          std::cout << p->getX() << ' ' << p->getY();
          scoreboard(p);
          break;
        case 'q':
          go = 0;
          break;
        default:
          w->printlvl(p->getX(), p->getY());
          break;
      }
    }
  }
  delete(p);
  delete(w);
  return 1;
}