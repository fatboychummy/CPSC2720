/**
 * @author MB Wilbern <matthew.wilbern>
 * @date 2019-01
**/


#include "Calculator.h"
#include "Exceptions.h"

Calculator::Calculator() {
  //Unrequired
}

Calculator::~Calculator() {
  //Unrequired
}

int Calculator::add(int x, int y) {
  // Self explanatory.
  return x + y;
}
int Calculator::sub(int x, int y) {
  // Self explanatory.
  return x - y;
}
int Calculator::mult(int x, int y) {
  // Self explanatory.
  return x * y;
}
float Calculator::div(int x, int y) {

  // IF y equals 0, then we should throw an error saying "it's not allowed."
  if (y == 0)
    throw div_by_zero_error("Cannot divide by zero.");

  // Cast one var to a float, so that it returns a float rather than an int, turned into a float
  return static_cast<float>(x) / y;
}
