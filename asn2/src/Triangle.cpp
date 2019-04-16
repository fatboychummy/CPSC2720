/**
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-02
*/

#include <cmath>
#include <string>
#include <limits>
#include "Triangle.h"
#include "Exceptions.h"

Triangle::Triangle(double s1, double s2, double s3):
  side1{s1}, side2{s2}, side3{s3} {
  std::string err = "Invalid parameter #";
  std::string err2 = ". All inputs must be positive";
  bool bad = false;
  if (s1 <= 0) {
    bad = true;
    err += "1" + err2;
  } else if (s2 <= 0) {
    bad = true;
    err += "2" + err2;
  } else if (s3 <= 0) {
    bad = true;
    err += "3" + err2;
  }
  // If one of the parameters are <= 0, add that to the string
  // "Invalid parameter #<param number>. All inputs must be positive"
  if (bad)
    throw invalid_parameter_error(
      err.c_str());
      // throw the error if there's an error

  if (!(s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1))
    throw invalid_parameter_error("This is an invalid triangle.");
}

double Triangle::area() const {
  double s = (side1 + side2 + side3) / 2;
  s = std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
  if (s > std::numeric_limits<double>::max())
    throw calculation_error("Could not calculate area due to overflow.");
  return s;
}

double Triangle::perimeter() const {
  double s1 = side1;
  double s2 = side2;
  double s3 = side3;
  if ((s1 < 0.0) == (s2 < 0.0)
      && std::abs(s2) > std::numeric_limits<double>::max() - std::abs(s1)
      || (s2 < 0.0) == (s3 < 0.0)
      && std::abs(s3) > std::numeric_limits<double>::max() - std::abs(s2)
      || (s1 < 0.0) == (s3 < 0.0)
      && std::abs(s3) > std::numeric_limits<double>::max() - std::abs(s1)
      || (s2 < 0.0) == (s1 < 0.0)
      && std::abs(s1) > std::numeric_limits<double>::max() - std::abs(s2)
      || (s3 < 0.0) == (s2 < 0.0)
      && std::abs(s2) > std::numeric_limits<double>::max() - std::abs(s3)
      || (s3 < 0.0) == (s1 < 0.0)
      && std::abs(s1) > std::numeric_limits<double>::max() - std::abs(s3))
    throw calculation_error("Could not calculate perimeter due to overflow.");
  return side1 + side2 + side3;
}

double Triangle::getSide1() const {
  return side1;
}

double Triangle::getSide2() const {
  return side2;
}

double Triangle::getSide3() const {
  return side3;
}
