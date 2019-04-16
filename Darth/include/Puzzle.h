/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_PUZZLE_H_
#define INCLUDE_PUZZLE_H_

#include <string>


class Puzzle {
 public:
  Puzzle();
  virtual ~Puzzle();

  virtual bool play() = 0;

  virtual std::string getName() = 0;

 protected:

  /**
  * Throws an error.
  */
  void quit();
};

#endif  // INCLUDE_PUZZLE_H_
