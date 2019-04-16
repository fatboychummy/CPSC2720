/**
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-02
*/

#include <cmath>
#include <limits>
#include <string>
#include "Quadrilateral.h"
#include "Exceptions.h"

Quadrilateral::Quadrilateral(double w, double h) :width{w}, height{h} {
  std::string err = "Invalid parameter #";
  std::string err2 = ". All inputs must be positive";
  bool bad = false;
  if (w <= 0) {
    bad = true;
    err += "1" + err2;
  } else if (h <= 0) {
    bad = true;
    err += "2" + err2;
  }
  // combine error strings, with the parameter that is erroring.
  if (bad)
    throw invalid_parameter_error(err.c_str());
  // throw the error.
}

double Quadrilateral::area() const {
  if (width * height > std::numeric_limits<double>::max())
    throw calculation_error
    ("Could not calculate the perimeter due to overflow.");
  return width * height;
  /*
    perimeter = w h
    2 checks:
      is w or h < 1? if so, don't do the second check.
      is w * h < w or h?
  */
}

double Quadrilateral::perimeter() const {
  if (((width < 0.0) == (height < 0.0)
       && std::abs(height)
       > std::numeric_limits<double>::max()
       - std::abs(width))
      || ((height < 0.0) == (width < 0.0)
          && std::abs(width)
          > std::numeric_limits<double>::max()
          - std::abs(height)))
    throw calculation_error
    ("Could not calculate the perimeter due to overflow.");
  // this works for checking overflow but the logic is currently beyond me.
  // thanks random person on google.
  return 2 * (width + height);
}

double Quadrilateral::getHeight() const {
  return height;
}

double Quadrilateral::getWidth() const {
  return width;
}
