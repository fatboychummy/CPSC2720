/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_KEYPADPUZZLE_H_
#define INCLUDE_KEYPADPUZZLE_H_

#include "Puzzle.h"
#include "Door.h"
#include "Player.h"

class KeyPadPuzzle : public Puzzle {
 public:
  KeyPadPuzzle(Player* p, int pass, Door* door,
    StatusEffect negative = StatusEffect::NONE, int time = 0);
  virtual ~KeyPadPuzzle();

  bool play();

  std::string getName();

 private:
  int passcode;
  Door* door;
  Player* p;
  StatusEffect n;
  int nTime;
};

#endif  // INCLUDE_KEYPADPUZZLE_H_
