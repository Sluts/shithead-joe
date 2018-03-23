#ifndef __PERSON_H__
#define __PERSON_H__
#define MAXITEMS 10
#define MAXBOREDOM 75
#define MAXCOFFEES 5
#define MAXHAPPINESS 90
#define MAXANGER 80

struct Person {
private:
  int strength;
  int intelligence;
  int money;
  int health;
  int boredom;
  int coffeesDrank;
  int hatCount;
  int anger;
  int speed;
  int direction; // 0 = north 1 = east 2 = south 3 = west
  int performance;
  int moving;
  int xPos;
  int yPos;
  
public:
  // getters
  int getStrength();
  int getIntelligence();
  int getMoney();
  int getHealth();
  int getBoredom();
  int getCoffeesDrank();
  int getHatCount();
  int getAnger();
  int getSpeed();
  int getDirection();
  int getPerformance();
  int getMoving();
  int getX();
  int getY();
  // setters
  void setStrength(int);
  void setIntelligence(int);
  void setMoney(int);
  int setHealth(int);
  void setBoredom(int);
  int setCoffeesDrank(int); // death setters return ints 1=alive 0=event caused death
  void setHatCount(int);
  void setAnger(int);
  void setSpeed(int);
  void setDirection(int);
  void setPerformance(int);
  void setMoving(int);
  // methods
  Person();
  void move(int, int);
  void die(int);

};

#endif