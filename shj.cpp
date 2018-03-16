#include <iostream>
#include "shj.h"

Joe::Joe(){
  hasHadCoffee = 0;
  coffees = 0;
  bored = 10;
  performance = 50;
};
void Joe::drinkCoffee() {
  performance = performance - (performance / 5);
  coffees++;
  bored = (bored - (coffees % 3)) - 3;
}
void Joe::giveWork() {
  if(performance >= 100){
    performance = 100;
  }
  if (coffees < 2){
    performance = performance + 2;
  } else {
    performance = performance + (2*coffees);
  }
  bored = bored + (performance / 3);
}
int Joe::getUse() {
  return performance;
}
int Joe::getCoffeeCount() {
  return coffees;
}
int Joe::getBored() {
  return bored;
}
void Joe::die() {
  std::cout << "RIP, Shithead Joe." << std::endl;
}