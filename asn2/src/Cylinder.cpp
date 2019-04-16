/**
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-02
*/

#include <cmath>
#include <limits>
#include <string>
#include "Cylinder.h"
#include "Exceptions.h"

Cylinder::Cylinder(double a, double b):height{b} {
  std::string err = "Invalid parameter #";
  std::string err2 = ". All inputs must be positive";
  bool bad = false;
  if (a <= 0) {
    bad = true;
    err += "1" + err2;
  } else if (b <= 0) {
    bad = true;
    err += "2" + err2;
  }
  // combine error strings, with the parameter that is erroring.
  if (bad)
    throw invalid_parameter_error(err.c_str());
  // throw the error.

  c = new Circle(a);
}

Cylinder::~Cylinder() {
  delete c;
}

double Cylinder::area() const {
  if (2 * (M_PI * getRadius() * height
           + M_PI * getRadius() * getRadius())
      > std::numeric_limits<double>::max())
    throw calculation_error("Could not calculate area due to overflow.");

  return 2 * (M_PI * getRadius() * height + M_PI * getRadius() * getRadius());
  /*
    2 pi r h + 2 pi r^2
  */
}

double Cylinder::volume() const {
  if (M_PI * getRadius() * getRadius() * height
      > std::numeric_limits<double>::max())
    throw calculation_error("Could not calculate volume due to overflow.");

  return M_PI * getRadius() * getRadius() * height;
  /*
    pi r^2 h
  */
}

double Cylinder::getHeight() const {
  return height;
}

double Cylinder::getRadius() const {
  return c->getRadius();
}
