#include <iostream>
#include "shj.h"
int main() {
  Joe joe;
  int go = 1;
  int score = 0;
  while(go) {
    system("cls");
    char opt[2];
    std::cout << "Score: " << score++ << std::endl;
    std::cout << "Coffees drank: " << joe.getCoffeeCount() << std::endl;
    std::cout << "Boredom: " << joe.getBored() << "%" << std::endl;
    std::cout << "Work: " << joe.getUse() << "%" << std::endl;
    std::cout << "1. Give Joe a coffee" << std::endl;
    std::cout << "2. Give Joe work" << std::endl;
    std::cout << "3. Quit" << std::endl;
    std::cin >> opt;
    if(*(opt) == '1') {
      joe.drinkCoffee();
    }
    if(*(opt) == '2') {
      joe.giveWork();
    }
    if(*(opt) == '3') {
      // this wont actually print. I mean, it will but the cls wont let you see it
      std::cout << "lol Fuck you, Joe... " << std::endl;
      --score;
      continue;
    }
    if(*(opt) == 'q') {
      go = 0;
    }
    if(joe.getCoffeeCount() >= 9) {
      std::cout << "Too much coffee, your tiny heart burst..." << std::endl;
      joe.die();
      go = 0;
      break;
    }
    if(joe.getBored() >= 100) {
      std::cout << "You died of boredom..." << std::endl;
      joe.die();
      go = 0;
      break;
    }
    if(joe.getUse() <= 20) {
      std::cout << "Too useless, you're fired..." << std::endl;
      joe.die();
      go = 0;
      break;
    }
    if(joe.getUse() > 100) {
      std::cout << "Too much work, you killed yourself..." << std::endl;
      joe.die();
      go = 0;
      break;
    }
  }
  return 1;
}