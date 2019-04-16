/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/
#ifndef INCLUDE_SHAPE3D_H_
#define INCLUDE_SHAPE3D_H_

#include "GeometricShape.h"

/**
    Interface for a three-dimensional shape.
*/

class Shape3D : public GeometricShape {
    /**
    *  @return The volume of the shape.
    */
    virtual double volume() const = 0;
};
#endif  // INCLUDE_SHAPE3D_H_
