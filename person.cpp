#include "person.h"
// getters
int Person::getStrength() {
  return this->strength;
}
int Person::getIntelligence() {
  return this->intelligence;
}
int Person::getMoney() {
  return this->money;
}
int Person::getHealth() {
  return this->health;
}
int Person::getBoredom() {
  return this->boredom;
}
int Person::getCoffeesDrank() {
  return this->coffeesDrank;
}
int Person::getHatCount() {
  return this->hatCount;
}
int Person::getAnger() {
  return this->anger;
}
int Person::getSpeed() {
  return this->speed;
}
int Person::getDirection() {
  return this->direction;
}
int Person::getPerformance() {
  return this->performance;
}
int Person::getMoving() {
  return this->moving;
}
int Person::getX() {
  return this->xPos;
}
int Person::getY() {
  return this->yPos;
}
int Person::getIsNazi() {
	return this->isNazi;
}
// setters
void Person::setStrength(int strength) {
  this->strength += strength;
  if(this->strength < 0) {
    this->strength = 0;
  }
}
void Person::setIntelligence(int intelligence) {
  this->intelligence += intelligence;
  if(this->intelligence < 0) {
    this->intelligence = 0;
  }
}
void Person::setMoney(int money) {
  this->money += money;
  if(this->money < 0) {
    this->money = 0;
  }
}
int Person::setHealth(int health) {
  this->health += health;
  if(this->health <= 0) {
    this->die(2);
    this->health = 0;
    return 0;
  }
  return 1;
}
void Person::setBoredom(int boredlvl) {
  this->boredom += boredlvl;
  if(this->boredom > MAXBOREDOM) {
    this->die(0);
  }
  if(this->boredom < 0) {
    this->boredom = 0;
  }
}
int Person::setCoffeesDrank(int coffees) {
  this->coffeesDrank += coffees;
  if(this->coffeesDrank > MAXCOFFEES) {
    this->die(1);
    return 0;
  }
  if(this->coffeesDrank < 0) {
    this->coffeesDrank = 0;
  }
  return 1;
}
void Person::setHatCount(int hats) {
  this->hatCount += hats;
}
void Person::setAnger(int anger) {
  this->anger += anger;
}
void Person::setSpeed(int speed) {
  this->speed += speed;
}
void Person::setDirection(int direction) {
  this->direction = direction;
}
void Person::setPerformance(int performance) {
  this->performance += performance;
}
void Person::setMoving(int moving) {
  this->moving = moving;
}
void Person::setIsNazi(int nazi) {
	this->isNazi = nazi;
}
// methods
Person::Person() {
  this->strength = 1;
  this->intelligence = 1;
  this->money = 5;
  this->health = 420;
  this->boredom = 0;
  this->coffeesDrank = 0;
  this->hatCount = 0;
  this->anger = 0;
  this->speed = 1;
  this->direction = 0; // 0 = north 1 = east 2 = south 3 = west
  this->performance = 0;
  this->moving = 0;
  this->xPos = 4;
  this->yPos = 5;
	this->isNazi = 0;
}
void Person::move(int x, int y) {
  this->xPos += x;
  this->yPos += y;
}
void Person::die(int why){
  
}