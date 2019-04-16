/**
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/
#ifndef INCLUDE_EXCEPTIONS_H_
#define INCLUDE_EXCEPTIONS_H_

#include <stdexcept>

/**
* Exception for when a player requests an item which is not there.
*/
class unavailable_item_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit unavailable_item_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for when a player requests a quest which is not there.
*/
class unavailable_quest_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit unavailable_quest_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for when a player quits a puzzle.
*/
class puzzle_quit_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit puzzle_quit_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};


#endif  // INCLUDE_EXCEPTIONS_H_
