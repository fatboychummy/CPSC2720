/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_ESCAPEBUTTONPUZZLE_H_
#define INCLUDE_ESCAPEBUTTONPUZZLE_H_

#include <string>
#include "Puzzle.h"


class EscapeButtonPuzzle : public Puzzle {
 public:
  explicit EscapeButtonPuzzle(bool *complete);
  virtual ~EscapeButtonPuzzle();

  bool play();

  std::string getName();

 private:
  void slowWrite(std::string stuff, unsigned int spd);
  bool* gameCompleter;
};

#endif  // INCLUDE_ESCAPEBUTTONPUZZLE_H_
