/**
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-02
*/


#include <cmath>
#include <limits>
#include "Circle.h"
#include "Exceptions.h"

Circle::Circle(double r):radius{r} {
  if (r <= 0)
    throw invalid_parameter_error("Circles must have a positive radius.");
  // if the radius is 0 or less, throw an error.
}

double Circle::area() const {
  if (radius > std::sqrt(std::numeric_limits<double>::max() / M_PI))
    throw calculation_error("That right there would cause an overflow.");

  return M_PI * radius * radius;
  /*
    area = pi r 2
    bigNum = pi r 2
    bigNum / pi = r 2
    root(bigNum / pi) = r
    the above determines the maximum allowed number
  */
}

double Circle::perimeter() const {
  if (radius > std::numeric_limits<double>::max() / (2 * M_PI))
    throw calculation_error("That right there would cause an overflow.");
  return 2 * M_PI * radius;  // initial shoddy implementation

  /*
    per = 2pi r
    bigNum = 2pi r
    bigNum / 2pi = r
    the above determines the maximum allowed number
  */
}

double Circle::getRadius() const {
  return radius;
}

