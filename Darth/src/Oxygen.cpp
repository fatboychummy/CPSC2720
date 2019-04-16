/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include "Oxygen.h"

Oxygen::Oxygen() {
  maxLevel = 9;
  oxygenLevel = maxLevel;
}

Oxygen::~Oxygen() {
  // dtor
}

int Oxygen::getOxygenLevel() {
  return oxygenLevel;
}

void Oxygen::setOxygenLevel(int level) {
  oxygenLevel = level;
}

void Oxygen::setMaxLevel(int level) {
  maxLevel = level;
}

int Oxygen::getMaxLevel() {
  return maxLevel;
}


void Oxygen::increase(int level) {
  oxygenLevel += level;
  if (oxygenLevel > maxLevel)
    oxygenLevel = maxLevel;
}

bool Oxygen::decrease(int count) {
  oxygenLevel -= count;
  if (oxygenLevel <= 0)
    return true;  // ONLY RETURN TRUE IF EQUAL TO 0
  // SO IT IS ONLY TRUE ONCE
  return false;
}
