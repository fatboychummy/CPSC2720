/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/
#ifndef INCLUDE_EXCEPTIONS_H_
#define INCLUDE_EXCEPTIONS_H_

#include <stdexcept>

/**
* This exception is run if PlayerFactory is handed a wrong-format string
*/
class invalid_format_error: public std::runtime_error {
 public:
  /**
  * @param err The message to be errored with
  */
  explicit invalid_format_error(const char* err) :
    std::runtime_error(err) {
  }
};

/**
* This exception is run if an observer is given invalid format.
*/
class invalid_observer_format_error: public std::runtime_error {
 public:
  /**
  * @param err The message to be errored with
  */
  explicit invalid_observer_format_error(const char* err) :
    std::runtime_error(err) {
  }
};

#endif  // INCLUDE_EXCEPTIONS_H_
