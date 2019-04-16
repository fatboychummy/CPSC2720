/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <unistd.h>
#include <iostream>
#include "DeathButtonPuzzle.h"
#include "Player.h"


DeathButtonPuzzle::DeathButtonPuzzle(Player* p) {
  player = p;
}

DeathButtonPuzzle::~DeathButtonPuzzle() {
}

bool DeathButtonPuzzle::play() {
  std::cout << "As you press the button, "
    << "a siren blares, and red lights begin flashing.\n\n"
    << "You hear a robotic voice announce, \n"
    << "\"SELF-DESTRUCT SEQUENCE INITIATED!  30 SECONDS REMAINING.\"\n";

  sleep(3);
  std::cout << "After running in circles for a little while, "
    << "you calm down enough "
    << "to realize just how screwed you are.\n";
  sleep(3);
  for (int i = 7; i > 0; --i) {
    if (i > 1)
      std::cout << "SELF DESTRUCTING IN " << i << " SECONDS.\n";
    else
      std::cout << "SELF DESTRUCTING IN " << i << " SECOND.\n";
    sleep(1);
  }
  std::cout << "keel da playa\n";
  player->setAlive(false);
}

std::string DeathButtonPuzzle::getName() {
  return "Press the Peculiar Button\n";
}
