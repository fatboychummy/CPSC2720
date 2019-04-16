/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <unistd.h>
#include <string>
#include <iostream>
#include "PasswordPuzzle.h"
#include "Player.h"

PasswordPuzzle::PasswordPuzzle(Player *p, std::string password,
                   std::string output,
                   std::string output2,
                   StatusEffect negative, int nTime) {
  this->p = p;
  pword = password;
  out = output;
  out2 = output2;
  n = negative;
  this->nTime = nTime;
}

bool PasswordPuzzle::play() {
  std::cout << out << "\n(q) quit\n\n>";
  std::string in;
  std::cin >> in;

  if (in == pword) {
    std::cout << out2 << std::endl;
    sleep(5);
    return true;
  } else if (in == "q" || in == "Q") {
    std::cout << "\nQuitting puzzle.\n";
    quit();
  }
  if (n == StatusEffect::COLD) {
    std::cout << "A blast of liquid nitrogen sprays over you.\n";
  } else if (n == StatusEffect::POISON) {
    std::cout << "A cloud of noxious gas sprays at you.\n";
  } else if (n == StatusEffect::ACID) {
    std::cout << "A blast of burning liquid sprays over you.\n";
  } else if (n == StatusEffect::FIRE) {
    std::cout << "A jet of fire shoots from at you.\n";
  } else {
    std::cout << "Incorrect answer.\n";
  }
  sleep(3);
  p->setStatus(n);
  p->setStatusTime(nTime);
  return false;
}

std::string PasswordPuzzle::getName() {
  return "Password Challenge\n";
}
