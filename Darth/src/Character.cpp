/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern, Kevin Baffo
// @date 2019-03
***********************************/

#include <string>
#include "Character.h"

Character::Character() {
}

void Character::setName(std::string const n) {
  name = n;
}

std::string Character::getName() {
  return name;
}

Character::~Character() {
  // dtor
}
