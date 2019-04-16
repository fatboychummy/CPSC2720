/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/
#ifndef INCLUDE_TRIANGLE_H_
#define INCLUDE_TRIANGLE_H_

#include <Shape2D.h>

/**
* Represents a triangle.<br>
     * See https://en.wikipedia.org/wiki/Triangle
     */
class Triangle : public Shape2D {
 public:
    /**
    * @param s1 length of first side
    * @param s2 length of second side
    * @param s3 length of third side
    * @throw invalid_parameter_error if a side is <= 0
    * @throw invalid_parameter_error if parameters create triangle that violates the Triangle Inequality Theorem.
    */
    Triangle(double s1, double s2, double s3);
    virtual ~Triangle() {}
    /**
      *  @return The area of the shape using Heron's formula (https://en.wikipedia.org/wiki/Heron's_formula).
      *  @throws calculation_error if the area cannot be correctly calculated.
      */
    double area() const;
    double perimeter() const;

    /**
    * @return the length of first side
    */
    double getSide1() const;

    /**
    * @return the length of second side
    */
    double getSide2() const;

    /**
    * @return the length of third side
    */
    double getSide3() const;

 private:
    double side1, side2, side3;
};
#endif  // INCLUDE_TRIANGLE_H_
