/**
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-02
*/


#include <cmath>
#include <limits>
#include <string>
#include "Cuboid.h"
#include "Exceptions.h"


Cuboid::Cuboid(double w, double h, double l):height{h} {
  std::string err = "Invalid parameter #";
  std::string err2 = ". All inputs must be positive";
  bool bad = false;
  if (w <= 0) {
    bad = true;
    err += "1" + err2;
  } else if (h <= 0) {
    bad = true;
    err += "2" + err2;
  } else if (l <= 0) {
    bad = true;
    err += "3" + err2;
  }
  // If one of the parameters are <= 0, add that to the string
  // "Invalid parameter #<param number>. All inputs must be positive"
  if (bad)
    throw invalid_parameter_error(
      err.c_str());
      // throw the error if there's an error

  q = new Quadrilateral(w, l);
  // create a quadrilateral, using width/length
}

Cuboid::~Cuboid() {
  delete q;  // deleto the quadrilateral
}

double Cuboid::area() const {
  if (2 * (getLength() * getWidth()
           + getLength() * height + height * getWidth())
      > std::numeric_limits<double>::max())
    throw calculation_error("Cannot calculate area as there was overflow.");
  // if overflow, throw error.

  return 2 * (getLength() * getWidth() + getLength() * height + height *
              getWidth());
  /*
    length * width + length * height + width * height
  */
}

double Cuboid::volume() const {
  if (height * getWidth() * getLength() > std::numeric_limits<double>::max())
    throw calculation_error("Cannot calculate volume as there was overflow.");
  // if overflow, throw error.
  return height * getWidth() * getLength();
  /*
    length * width * height
  */
}

double Cuboid::getHeight() const {
  return height;
  // so this function does something which is simply brilliant.
  // it transcends through time and space,
  // just so it can slap a number into your terminal.
}

double Cuboid::getWidth() const {
  return q->getWidth();
}

double Cuboid::getLength() const {
  return q->getHeight();
}

