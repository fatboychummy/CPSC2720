/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/

#include <cmath>
#include <limits>
#include "gtest/gtest.h"
#include <Exceptions.h>
#include <Cuboid.h>


// Test Cuboid (area, volume, getHeight, getWidth, getLength)

// Test the getWidth/Height/Length functions

TEST(TestCuboid, getWidth) {
  double width = 23.2;
  double height = 34.6;
  double length = 11.7;

  Cuboid *c = new Cuboid(width, height, length);

  EXPECT_NEAR(c->getWidth(), width, 0.0001);    // Test width function

  delete c;
}

TEST(TestCuboid, getHeight) {
  double width = 23.2;
  double height = 34.6;
  double length = 11.7;

  Cuboid *c = new Cuboid(width, height, length);

  EXPECT_NEAR(c->getHeight(), height, 0.0001);  // Test height function

  delete c;
}

TEST(TestCuboid, getLength) {
  double width = 23.2;
  double height = 34.6;
  double length = 11.7;

  Cuboid *c = new Cuboid(width, height, length);

  EXPECT_NEAR(c->getLength(), length, 0.0001);  // Test length function

  delete c;
}


// Ignoring what width/height/length return, test area/volume functions

TEST(TestCuboid, area) {
  double width = 23.2;
  double height = 34.6;
  double length = 11.7;
  double volume = length * width * height;
  double area = (2 * length * width) + (2 * length * height)
                + (2 * height * width);

  Cuboid *c = new Cuboid(width, height, length);

  EXPECT_NEAR(c->area(), area, 0.0001);     // Test area function

  delete c;
}

TEST(TestCuboid, volume) {
  double width = 23.2;
  double height = 34.6;
  double length = 11.7;
  double volume = length * width * height;
  double area = (2 * length * width) + (2 * length * height)
                + (2 * height * width);

  Cuboid *c = new Cuboid(width, height, length);

  EXPECT_NEAR(c->volume(), volume, 0.0001);  // Test volume function

  delete c;
}

// Exceptions test

TEST(TestCuboid, invalidParam1) {
  double width = std::numeric_limits<double>::max();
  double height = 2;
  double length = 2;
  Cuboid *c = new Cuboid(width, height, length);

  EXPECT_THROW(Cuboid(-1, 1, 1), invalid_parameter_error);

  delete c;
}

TEST(TestCuboid, invalidParam2) {
  double width = std::numeric_limits<double>::max();
  double height = 2;
  double length = 2;
  Cuboid *c = new Cuboid(width, height, length);

  EXPECT_THROW(Cuboid(1, -1, 1), invalid_parameter_error);

  delete c;
}

TEST(TestCuboid, invalidParam3) {
  double width = std::numeric_limits<double>::max();
  double height = 2;
  double length = 2;
  Cuboid *c = new Cuboid(width, height, length);

  EXPECT_THROW(Cuboid(1, 1, -1), invalid_parameter_error);

  delete c;
}

TEST(TestCuboid, overflowArea) {
  double width = std::numeric_limits<double>::max();
  double height = 2;
  double length = 2;
  Cuboid *c = new Cuboid(width, height, length);

  EXPECT_THROW(c->area(), calculation_error);

  delete c;
}

TEST(TestCuboid, overflowVolume) {
  double width = std::numeric_limits<double>::max();
  double height = 2;
  double length = 2;
  Cuboid *c = new Cuboid(width, height, length);

  EXPECT_THROW(c->volume(), calculation_error);

  delete c;
}

