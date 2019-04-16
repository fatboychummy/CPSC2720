/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/

#include <cmath>
#include <limits>
#include "Quadrilateral.h"
#include "gtest/gtest.h"
#include <Exceptions.h>
#include <Circle.h>
#include <Cuboid.h>
#include <Cylinder.h>
#include <Triangle.h>




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
  double area = M_PI * radius * radius; // Area = pi r^2
  Circle *c = new Circle(radius);
  EXPECT_NEAR(c->area(), area, 0.0001);

  delete c;
}

// Test the perimeter function

TEST(TestCircle, perimeter) {
  double radius = 53.3;
  double peri = 2 * M_PI * radius; // Perimeter = 2 pi r
  Circle *c = new Circle(radius);
  EXPECT_NEAR(c->perimeter(), peri, 0.0001);

  delete c;
}

// Exceptions test

TEST(TestCircle, exceptions) {
  double rad = std::numeric_limits<double>::max();
  Circle *c = new Circle(rad);

  EXPECT_THROW(Circle(-1), invalid_parameter_error);
  EXPECT_THROW(c->perimeter(), calculation_error);
  EXPECT_THROW(c->area(), calculation_error);

  delete c;
}

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

TEST(TestCuboid, areaVolume) {
  double width = 23.2;
  double height = 34.6;
  double length = 11.7;
  double volume = length * width * height;
  double area = (2 * length * width) + (2 * length * height)
                + (2 * height * width);

  Cuboid *c = new Cuboid(width, height, length);

  EXPECT_NEAR(c->area(), area, 0.0001);     // Test area function
  EXPECT_NEAR(c->volume(), volume, 0.0001); // Test volume function

  delete c;
}

// Exceptions test

TEST(TestCuboid, exceptions) {
  double width = std::numeric_limits<double>::max();
  double height = 2;
  double length = 2;
  Cuboid *c = new Cuboid(width, height, length);

  EXPECT_THROW(Cuboid(-1, 1, 1), invalid_parameter_error);
  EXPECT_THROW(Cuboid(1, -1, 1), invalid_parameter_error);
  EXPECT_THROW(Cuboid(1, 1, -1), invalid_parameter_error);
  EXPECT_THROW(c->area(), calculation_error);
  EXPECT_THROW(c->volume(), calculation_error);

  delete c;
}

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
  double volume = M_PI * radius * radius * height; // Volume = PI r^2 h

  Cylinder *c = new Cylinder(radius, height);

  EXPECT_NEAR(c->volume(), volume, 0.0001);

  delete c;
}

// Test exceptions

TEST(TestCylinder, exceptions) {
  double radius = std::numeric_limits<double>::max();
  double height = 2;
  Cylinder *c = new Cylinder(radius, height);

  EXPECT_THROW(Cylinder(-1, 1), invalid_parameter_error);
  EXPECT_THROW(Cylinder(1, -1), invalid_parameter_error);
  EXPECT_THROW(c->area(), calculation_error);
  EXPECT_THROW(c->volume(), calculation_error);

  delete c;
}

// Test Quadrilateral (getHeight, getWidth, area, volume)

// Test getHeight/Width functions

TEST(TestQuadrilateral, getDimensions) {
  double height = 41.5;
  double width = 341.3;

  Quadrilateral *q = new Quadrilateral(width, height);

  EXPECT_NEAR(q->getHeight(), height, 0.0001);
  EXPECT_NEAR(q->getWidth(), width, 0.0001);

  delete q;
}

// Test area/perimeter functions

TEST(TestQuadrilateral, areaPerimeter) {
  double height = 21.24;
  double width = 5.2;
  double area = width * height;
  double perimeter = (2 * width) + (2 * height);

  Quadrilateral *q = new Quadrilateral(width, height);

  EXPECT_NEAR(q->area(), area, 0.0001);
  EXPECT_NEAR(q->perimeter(), perimeter, 0.0001);

  delete q;
}

// Test exceptions

TEST(TestQuadrilateral, exceptions) {
  double height = std::numeric_limits<double>::max();
  double width = 2;

  Quadrilateral *q = new Quadrilateral(width, height);

  EXPECT_THROW(Quadrilateral(-1, 1), invalid_parameter_error);
  EXPECT_THROW(Quadrilateral(1, -1), invalid_parameter_error);
  EXPECT_THROW(q->area(), calculation_error);
  EXPECT_THROW(q->perimeter(), calculation_error);

  delete q;
}

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

TEST(TestTriangle, areaPerimeter) {
  double s1 = 13.2;
  double s2 = 8;
  double s3 = 7.8;
  double per = s1 + s2 + s3;
  double p = per/2;
  double area = sqrt(p * (p - s1) * (p - s2) * (p - s3));
  // Area = sqrt(p(p-a)(p-b)(p-c)), where p is half the perimeter

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_NEAR(t->perimeter(), per, 0.0001);
  EXPECT_NEAR(t->area(), area, 0.0001);

  delete t;
}

// Test exceptions

TEST(TestTriangle, exceptions) {
  double s1 = std::numeric_limits<double>::max();
  double s2 = std::numeric_limits<double>::max();
  double s3 = std::numeric_limits<double>::max();

  Triangle *t = new Triangle(s1, s2, s3);

  EXPECT_THROW(Triangle(-1, 1, 1), invalid_parameter_error);
  EXPECT_THROW(Triangle(1, -1, 1), invalid_parameter_error);
  EXPECT_THROW(Triangle(1, 1, -1), invalid_parameter_error);
  EXPECT_THROW(Triangle(1, 1, 3), invalid_parameter_error);
  EXPECT_THROW(t->area(), calculation_error);
  EXPECT_THROW(t->perimeter(), calculation_error);

  delete t;
}
