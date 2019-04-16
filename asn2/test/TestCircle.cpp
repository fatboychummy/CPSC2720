/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/

#include <cmath>
#include <limits>
#include <Exceptions.h>
#include "gtest/gtest.h"
#include "Circle.h"



// Test Circle ( Circle, area, perimeter, getRadius )

// Test the getRadius function
TEST(TestCircle, getRadius) {
  double radius = 3.7;
  Circle *c = new Circle(radius);
  EXPECT_NEAR(c->getRadius(), radius, 0.0001);

  delete c;
}

// Test the area function
TEST(TestCircle, area) {
  double radius = 6.0;
  double area = M_PI * radius * radius;  // Area = pi r^2
  Circle *c = new Circle(radius);
  EXPECT_NEAR(c->area(), area, 0.0001);

  delete c;
}

// Test the perimeter function

TEST(TestCircle, perimeter) {
  double radius = 53.3;
  double peri = 2 * M_PI * radius;  // Perimeter = 2 pi r
  Circle *c = new Circle(radius);
  EXPECT_NEAR(c->perimeter(), peri, 0.0001);

  delete c;
}

// Exceptions test

TEST(TestCircle, invalidParam) {
  double rad = std::numeric_limits<double>::max();
  Circle *c = new Circle(rad);

  EXPECT_THROW(Circle(-1), invalid_parameter_error);

  delete c;
}

TEST(TestCircle, overflowErrPerim) {
  double rad = std::numeric_limits<double>::max();
  Circle *c = new Circle(rad);

  EXPECT_THROW(c->perimeter(), calculation_error);

  delete c;
}

TEST(TestCircle, overflowErrArea) {
  double rad = std::numeric_limits<double>::max();
  Circle *c = new Circle(rad);

  EXPECT_THROW(c->area(), calculation_error);

  delete c;
}
