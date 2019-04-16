/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/
#ifndef INCLUDE_SHAPE2D_H_
#define INCLUDE_SHAPE2D_H_

#include "GeometricShape.h"

/**
    Interface for a two-dimensional shape.
*/
class Shape2D : public GeometricShape {
    /**
    *  @return The perimeter of the shape.
    *  @throws calculation_error if the perimeter cannot be correctly calculated.
    */
    virtual double perimeter() const = 0;
};
#endif  // INCLUDE_SHAPE2D_H_
