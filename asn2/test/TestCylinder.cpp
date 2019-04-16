/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/

#include <cmath>
#include <limits>
#include <Exceptions.h>
#include "gtest/gtest.h"
#include "Cylinder.h"


// Test Cylinder (area, getHeight, getRadius, volume)

// Test getHeight function

TEST(TestCylinder, getRadius) {
  double radius = 21.3;
  double height = 41.2;

  Cylinder *c = new Cylinder(radius, height);

  EXPECT_NEAR(c->getRadius(), radius, 0.0001);

  delete c;
}

TEST(TestCylinder, getHeight) {
  double radius = 21.3;
  double height = 41.2;

  Cylinder *c = new Cylinder(radius, height);

  EXPECT_NEAR(c->getHeight(), height, 0.0001);

  delete c;
}

// Test area and volume functions

TEST(TestCylinder, area) {
  double radius = 6.4;
  double height = 8.5;
  double area = (2 * M_PI * radius * height)
  + (2 * M_PI * radius * radius);  // Area = 2PIr + 2PIr^2

  Cylinder *c = new Cylinder(radius, height);

  EXPECT_NEAR(c->area(), area, 0.0001);

  delete c;
}

TEST(TestCylinder, volume) {
  double radius = 6.4;
  double height = 8.5;
  double volume = M_PI * radius * radius * height;  // Volume = PI r^2 h

  Cylinder *c = new Cylinder(radius, height);

  EXPECT_NEAR(c->volume(), volume, 0.0001);

  delete c;
}

// Test exceptions

TEST(TestCylinder, invalidParam1) {
  double radius = std::numeric_limits<double>::max();
  double height = 2;
  Cylinder *c = new Cylinder(radius, height);

  EXPECT_THROW(Cylinder(-1, 1), invalid_parameter_error);

  delete c;
}

TEST(TestCylinder, invalidParam2) {
  double radius = std::numeric_limits<double>::max();
  double height = 2;
  Cylinder *c = new Cylinder(radius, height);

  EXPECT_THROW(Cylinder(1, -1), invalid_parameter_error);

  delete c;
}

TEST(TestCylinder, overflowArea) {
  double radius = std::numeric_limits<double>::max();
  double height = 2;
  Cylinder *c = new Cylinder(radius, height);

  EXPECT_THROW(c->area(), calculation_error);

  delete c;
}

TEST(TestCylinder, overflowVolume) {
  double radius = std::numeric_limits<double>::max();
  double height = 2;
  Cylinder *c = new Cylinder(radius, height);

  EXPECT_THROW(c->volume(), calculation_error);

  delete c;
}
