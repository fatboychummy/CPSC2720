/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern, Kevin Baffo
// @date 2019-03
***********************************/

#include "Door.h"

Door::~Door() {
  // dtor
}

Door::Door(int cRoom1, int cRoom2, bool locked) {
  r1 = cRoom1;
  r2 = cRoom2;
  this->locked = locked;
  openable = true;
}

int Door::getRoomID1() {
  return r1;
}

int Door::getRoomID2() {
  return r2;
}

void Door::destroy() {
  openable = false;
}

void Door::unlock() {
  locked = false;
}

bool Door::canOpen() {
  if (locked == true || openable == false)
    return false;
  else
    return true;
}

bool Door::isLocked() {
  return locked;
}
