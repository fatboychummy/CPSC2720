/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_CHARACTER_H_
#define INCLUDE_CHARACTER_H_

#include <string>

class Character {
 public:
  Character();
  virtual ~Character();

  /**
  * @return the name of the character.
  */
  std::string getName();

  /**
  * @param name set the name of the character
  */
  void setName(std::string name);
 private:
  std::string name;
};

#endif  // INCLUDE_CHARACTER_H_
