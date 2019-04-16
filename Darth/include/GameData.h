/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_GAMEDATA_H_
#define INCLUDE_GAMEDATA_H_

#include <string>
#include "Ship.h"

/**
* Allows for the saving and loading of the game.<br>
*/
class GameData {
 public:
  GameData();
  virtual ~GameData();

  /**
  * @return if the file was able to be saved.
  */
  bool save();

  /**
  * @return if the file was able to be loaded.
  */
  bool load();

  /**
  * @param s the DIRECT (from root) file location to be saved to.
  */
  void setFileLocation(std::string s);

  /**
  * @param ship the ship that we want to save.
  */
  void setShip(Ship *ship);

 private:
  /**
  * @param ship the ship which holds all the data to be saved.
  * @return a string which can be written to a file.
  */
  std::string serialize(Ship *ship);

  /**
  * @param data the string of data to be unserialized.
  * @return data to be used.
  */
  Ship* unserialize(std::string data);

  Ship* theShip;          // stores the ship we want to save
  std::string fileLocation;    // stores the file location we want to save to
  bool fileSet = false;   // if the file location has been set yet or not
};

#endif  // INCLUDE_GAMEDATA_H_
