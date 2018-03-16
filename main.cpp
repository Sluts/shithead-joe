#include <iostream>
#include "person.h"
#include "world.h"

void checkPos(Person*, World*);
void commitMovement(Person*, World*);

void checkPos(Person* p, World* w) {
  switch(w->getCurrentLvl()) {
    case(0):
      if(p->getX() == 3 && p->getY() == 4) {
        w->changeWorld(1);
        p->move(19 - p->getX(), 13 - p->getY());
      }
      if(p->getX() == 3 && p->getY() == 10) {
        w->changeWorld(2);
        p->move(10 - p->getX(), 20 - p->getY());
      }
      break;
    case(1):
      if(p->getX() == 20 && p->getY() == 13) {
        w->changeWorld(0);
        p->move(3 - p->getX(), 5 - p->getY());
      }
      break;
    case(2):
      if(p->getX() == 10 && p->getY() == 20) {
        w->changeWorld(0);
        p->move(3 - p->getX(), 11 - p->getY());
      }
      break;
    default:
      break;
  }
}

void commitMovement(Person* p, World* w) {
  int hit;
  hit = w->evalPos(p->getX(), p->getY());
  switch(hit) {
    case(1):
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
  }
}

int main() {
  Person* p = new Person();
  World* w = new World();
  int go, hit;
  char userIn;
  go = 1;
  while(go) {
    // system("cls");
    w->printlvl(p->getX(), p->getY());
    std::cin >> userIn;
    if(userIn == 'w') {
      p->move(0, -1);
      p->setDirection(0);
    }                            
    else if(userIn == 'd') {          
      p->move(1, 0);              
      p->setDirection(1);     
    }                            
    else if(userIn == 's') {          
      p->move(0, 1);              
      p->setDirection(2);
    }
    else if(userIn == 'a') {
      p->move(-1, 0);
      p->setDirection(3);
    }
    commitMovement(p, w);
    checkPos(p, w);
    if(userIn == 'q') {
      go = 0;
    }
    std::cout << p->getX() << ", " << p->getY() << std::endl;
  }
  delete(p);
  delete(w);
  return 1;
}