/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/
#ifndef INCLUDE_CYLINDER_H_
#define INCLUDE_CYLINDER_H_

#include <Shape3D.h>
#include "Circle.h"

/**
* Represents a cylinder.<br>
   * See https://en.wikipedia.org/wiki/Cylinder_(geometry)
   */
class Cylinder : public Shape3D {
 public:
   /**
    * @param r the radius of the cone.
    * @param h the height of the cone.
    * @throws invalid_parameter_error if radius or height is <= 0
    */
    Cylinder(double r, double h);
    virtual ~Cylinder();
    double area() const;
    double volume() const;

    /**
    * @return the height.
    */
    double getHeight() const;

    /**
    * @return the radius.
    */
    double getRadius() const;

 private:
    Circle* c;
    double height;
};

#endif  // INCLUDE_CYLINDER_H_
