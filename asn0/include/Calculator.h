/**
 * @author MB Wilbern <matthew.wilbern>
 * @date 2019-01
**/

#ifndef CALCULATOR_H
#define CALCULATOR_H


class Calculator {
 public:
  // Constructor / Deconstructor
  Calculator();
  virtual ~Calculator();

  // arithmetic methods
  int add(int, int);
  int sub(int, int);
  int mult(int, int);
  float div(int, int);
};

#endif // CALCULATOR_H
