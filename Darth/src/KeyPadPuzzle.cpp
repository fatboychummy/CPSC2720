/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <unistd.h>
#include <iostream>
#include "KeyPadPuzzle.h"
#include "Door.h"
#include "Player.h"

KeyPadPuzzle::KeyPadPuzzle(Player *p, int pass, Door* door,
                           StatusEffect negative, int time) {
  this->p = p;
  passcode = pass;
  this->door = door;
  n = negative;
  nTime = time;
}

KeyPadPuzzle::~KeyPadPuzzle() {
}

bool KeyPadPuzzle::play() {
  int c = 0;
  std::cout << "You sight a keypad and walk up to it.  "
            "You touch your hand to a key, and the display lights up."
            "\n\n(negative number) Quit\n\nENTER CODE: ";
  std::cin >> c;
  if (c == passcode) {
    std::cout << "\nThe screen flashes green\n";
    sleep(3);
    door->unlock();
    return true;
  } else if (c <= 0) {
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

std::string KeyPadPuzzle::getName() {
  return "Use Keypad\n";
}
