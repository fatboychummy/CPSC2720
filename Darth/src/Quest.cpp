/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <string>
#include "Quest.h"

Quest::Quest() {
  // ctor
}

Quest::~Quest() {
  // dtor
}

void Quest::setInfo(std::string info) {
  this->info = info;
}

void Quest::setName(std::string name) {
  this->name = name;
}

std::string Quest::getName() {
  return name;
}

std::string Quest::getInfo() {
  return info;
}

bool Quest::isCompleted() {
  return completed;
}

void Quest::completeQuest() {
  completed = true;
}
