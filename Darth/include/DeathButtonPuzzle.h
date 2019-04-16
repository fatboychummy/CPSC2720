/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_DEATHBUTTONPUZZLE_H_
#define INCLUDE_DEATHBUTTONPUZZLE_H_

#include "Puzzle.h"
#include "Player.h"


class DeathButtonPuzzle : public Puzzle {
 public:
  explicit DeathButtonPuzzle(Player* p);
  virtual ~DeathButtonPuzzle();

  bool play();

  std::string getName();

 private:
  Player* player;
};

#endif  // INCLUDE_DEATHBUTTONPUZZLE_H_
