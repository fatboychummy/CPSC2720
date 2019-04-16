/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/

#include <cmath>
#include <limits>
#include "gtest/gtest.h"
#include <Exceptions.h>
#include <Triangle.h>


// Test Triangle (area, perimeter, getSide1-3)

// Test getSide1/2/3

TEST(TestTriangle, getSide1) {
  double s1 = 13.2;
  double s2 = 8;
  double s3 = 7.8;

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_NEAR(t->getSide1(), s1, 0.0001);

  delete t;
}

TEST(TestTriangle, getSide2) {
  double s1 = 13.2;
  double s2 = 8;
  double s3 = 7.8;

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_NEAR(t->getSide2(), s2, 0.0001);

  delete t;
}

TEST(TestTriangle, getSide3) {
  double s1 = 13.2;
  double s2 = 8;
  double s3 = 7.8;

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_NEAR(t->getSide3(), s3, 0.0001);

  delete t;
}

// Test area/perimeter functions

TEST(TestTriangle, area) {
  double s1 = 13.2;
  double s2 = 8;
  double s3 = 7.8;
  double per = s1 + s2 + s3;
  double p = per/2;
  double area = sqrt(p * (p - s1) * (p - s2) * (p - s3));
  // Area = sqrt(p(p-a)(p-b)(p-c)), where p is half the perimeter

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_NEAR(t->area(), area, 0.0001);

  delete t;
}

TEST(TestTriangle, perimeter) {
  double s1 = 13.2;
  double s2 = 8;
  double s3 = 7.8;
  double per = s1 + s2 + s3;
  double p = per/2;
  double area = sqrt(p * (p - s1) * (p - s2) * (p - s3));
  // Area = sqrt(p(p-a)(p-b)(p-c)), where p is half the perimeter

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_NEAR(t->perimeter(), per, 0.0001);

  delete t;
}

// Test exceptions

TEST(TestTriangle, invalidParam1) {
  double s1 = std::numeric_limits<double>::max();
  double s2 = std::numeric_limits<double>::max();
  double s3 = std::numeric_limits<double>::max();

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_THROW(Triangle(-1, 1, 1), invalid_parameter_error);
  delete t;
}

TEST(TestTriangle, invalidParam2) {
  double s1 = std::numeric_limits<double>::max();
  double s2 = std::numeric_limits<double>::max();
  double s3 = std::numeric_limits<double>::max();

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_THROW(Triangle(1, -1, 1), invalid_parameter_error);

  delete t;
}

TEST(TestTriangle, invalidParam3) {
  double s1 = std::numeric_limits<double>::max();
  double s2 = std::numeric_limits<double>::max();
  double s3 = std::numeric_limits<double>::max();

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_THROW(Triangle(1, 1, -1), invalid_parameter_error);

  delete t;
}

TEST(TestTriangle, invalidTriangle) {
  double s1 = std::numeric_limits<double>::max();
  double s2 = std::numeric_limits<double>::max();
  double s3 = std::numeric_limits<double>::max();

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_THROW(Triangle(1, 1, 3), invalid_parameter_error);

  delete t;
}

TEST(TestTriangle, overflowArea) {
  double s1 = std::numeric_limits<double>::max();
  double s2 = std::numeric_limits<double>::max();
  double s3 = std::numeric_limits<double>::max();

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_THROW(t->area(), calculation_error);

  delete t;
}

TEST(TestTriangle, overflowPerimeter) {
  double s1 = std::numeric_limits<double>::max();
  double s2 = std::numeric_limits<double>::max();
  double s3 = std::numeric_limits<double>::max();

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_THROW(t->perimeter(), calculation_error);

  delete t;
}
