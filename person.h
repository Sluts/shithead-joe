#ifndef __PERSON_H__
#define __PERSON_H__
#define MAXITEMS 10
#define MAXBOREDOM 75
#define MAXCOFFEES 20
#define MAXHAPPINESS 90
#define MAXANGER 80

struct Person {
private:
  int boredom;
  int coffeesDrank;
  int hatCount;
  int anger;
  int speed;
  int direction; // 0 = north 1 = east 2 = south 3 = west
  int performance;
  int happiness;
  int moving;
  int xPos;
  int yPos;
  
public:
  // getters
  int getBoredom();
  int getCoffeesDrank();
  int getHatCount();
  int getAnger();
  int getSpeed();
  int getDirection();
  int getPerformance();
  int getHappiness();
  int getMoving();
  int getX();
  int getY();
  // setters
  void setBoredom(int);
  void setCoffeesDrank(int);
  void setHatCount(int);
  void setAnger(int);
  void setSpeed(int);
  void setDirection(int);
  void setPerformance(int);
  void setHappiness(int);
  void setMoving(int);
  // methods
  Person();
  void move(int, int);
  void die(int);

};

#endif