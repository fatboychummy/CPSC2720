/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/

#include <cmath>
#include <limits>
#include "Quadrilateral.h"
#include "gtest/gtest.h"
#include <Exceptions.h>


// Test Quadrilateral (getHeight, getWidth, area, volume)

// Test getHeight/Width functions

TEST(TestQuadrilateral, getHeight) {
  double height = 41.5;
  double width = 341.3;

  Quadrilateral *q = new Quadrilateral(width, height);

  EXPECT_NEAR(q->getHeight(), height, 0.0001);


  delete q;
}

TEST(TestQuadrilateral, getWidth) {
  double height = 41.5;
  double width = 341.3;

  Quadrilateral *q = new Quadrilateral(width, height);

  EXPECT_NEAR(q->getWidth(), width, 0.0001);

  delete q;
}

// Test area/perimeter functions

TEST(TestQuadrilateral, area) {
  double height = 21.24;
  double width = 5.2;
  double area = width * height;
  double perimeter = (2 * width) + (2 * height);

  Quadrilateral *q = new Quadrilateral(width, height);

  EXPECT_NEAR(q->area(), area, 0.0001);

  delete q;
}

TEST(TestQuadrilateral, perimeter) {
  double height = 21.24;
  double width = 5.2;
  double area = width * height;
  double perimeter = (2 * width) + (2 * height);

  Quadrilateral *q = new Quadrilateral(width, height);

  EXPECT_NEAR(q->perimeter(), perimeter, 0.0001);

  delete q;
}

// Test exceptions

TEST(TestQuadrilateral, invalidParam1) {
  double height = std::numeric_limits<double>::max();
  double width = 2;

  Quadrilateral *q = new Quadrilateral(width, height);

  EXPECT_THROW(Quadrilateral(-1, 1), invalid_parameter_error);

  delete q;
}

TEST(TestQuadrilateral, invalidParam2) {
  double height = std::numeric_limits<double>::max();
  double width = 2;

  Quadrilateral *q = new Quadrilateral(width, height);

  EXPECT_THROW(Quadrilateral(1, -1), invalid_parameter_error);

  delete q;
}

TEST(TestQuadrilateral, overflowArea) {
  double height = std::numeric_limits<double>::max();
  double width = 2;

  Quadrilateral *q = new Quadrilateral(width, height);

  EXPECT_THROW(q->area(), calculation_error);

  delete q;
}

TEST(TestQuadrilateral, overflowPerimeter) {
  double height = std::numeric_limits<double>::max();
  double width = 500;

  Quadrilateral *q = new Quadrilateral(width, height);

  EXPECT_THROW(q->perimeter(), calculation_error);

  delete q;
}


