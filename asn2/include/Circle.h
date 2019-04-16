/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <Shape2D.h>

/**
* Represents a circle.<br>
     * See https://en.wikipedia.org/wiki/Circle
     */
class Circle : public Shape2D {
 public:
    /**
    * @param r the radius of the circle.
    * @throws invalid_parameter_error if radius is <= 0
    */
    explicit Circle(double r);
    virtual ~Circle() {}
    double area() const;
    double perimeter() const;

    /**
    * @return radius of the circle
    */
    double getRadius() const;

 private:
    double radius;
};

#endif  // INCLUDE_CIRCLE_H_
