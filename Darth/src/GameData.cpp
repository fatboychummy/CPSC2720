/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <iostream>
#include <fstream>
#include <string>
#include "GameData.h"

GameData::GameData() {
}

GameData::~GameData() {
  delete theShip;
}

bool GameData::save() {
  /*
  if (fileSet) {  // If the file has been set ...
    std::ofstream out(fileLocation);
    if (out) {  // If the file is valid (did it open?) ...
      out << GameData::serialize(theShip);
      // Output the serialized data.
      return true;
    }
  }
  return false;
  */
}

bool GameData::load() {
  /*
  if (fileSet) {  // If the file has been set ...
    std::ifstream out(fileLocation);
    if (out) {  // If the file is valid (did it open?) ...
      std::string dat;
      out >> dat;
      theShip = GameData::unserialize(dat);
      // read to dat, then save to ship
      return true;
    }
  }
  return false;
  */
}

void GameData::setFileLocation(std::string s) {
  fileLocation = s;
}

void GameData::setShip(Ship* ship) {
  theShip = ship;
}

std::string GameData::serialize(Ship* ship) {
  return "It does not work yet";
}

Ship* GameData::unserialize(std::string data) {
  Ship *h = new Ship();
  return h;
}
