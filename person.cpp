#include "person.h"
// getters
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
int Person::getHappiness() {
  return this->happiness;
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
// setters
void Person::setMoney(int money) {
  this->money += money;
}
void Person::setHealth(int health) {
  this->health += health;
}
void Person::setBoredom(int boredlvl) {
  this->boredom += boredlvl;
  if(this->boredom > MAXBOREDOM) {
    this->die(0);
  }
}
void Person::setCoffeesDrank(int coffees) {
  this->coffeesDrank += coffees;
  if(this->coffeesDrank > MAXCOFFEES) {
    this->die(1);
  }
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
void Person::setHappiness(int happiness) {
  this->happiness += happiness;
}
void Person::setMoving(int moving) {
  this->moving = moving;
}
// methods
Person::Person() {
  this->money = 5;
  this->health = 420;
  this->boredom = 0;
  this->coffeesDrank = 0;
  this->hatCount = 0;
  this->anger = 0;
  this->speed = 1;
  this->direction = 0; // 0 = north 1 = east 2 = south 3 = west
  this->performance = 0;
  this->happiness = 50;
  this->moving = 0;
  this->xPos = 4;
  this->yPos = 5;
}
void Person::move(int x, int y) {
  this->xPos += x;
  this->yPos += y;
}
void Person::die(int why){

}