/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include "Puzzle.h"
#include "Exceptions.h"

Puzzle::Puzzle() {
}

Puzzle::~Puzzle() {
}

void Puzzle::quit() {
  throw
    puzzle_quit_error("The player has quit the current puzzle.");
}
