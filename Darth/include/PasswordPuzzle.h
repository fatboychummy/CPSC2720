/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_PASSWORDPUZZLE_H_
#define INCLUDE_PASSWORDPUZZLE_H_

#include <string>
#include "Puzzle.h"
#include "Player.h"


class PasswordPuzzle : public Puzzle {
 public:
  PasswordPuzzle(Player *p, std::string password, std::string output,
                 std::string output2,
                 StatusEffect negative = StatusEffect::NONE, int nTime = 0);

  bool play();

  std::string getName();

 private:
  std::string pword;
  std::string out;
  std::string out2;
  Player *p;
  StatusEffect n;
  int nTime;
};

#endif  // INCLUDE_PASSWORDPUZZLE_H_
