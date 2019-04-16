/**
 * @author MB Wilbern <matthew.wilbern>
 * @date 2019-01
**/

#include "Calculator.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

//Begin tests

TEST(TestCalculator, addTest) {
  // Add 1 + 2, Expecting 3
  Calculator c;
  EXPECT_EQ(3, c.add(1, 2));
}

TEST(TestCalculator, subTest) {
  // Subtract 8 - 4, expecting 4
  Calculator c;
  EXPECT_EQ(4, c.sub(8, 4));
}

TEST(TestCalculator, multTest) {
  // Multiply 8 * 2, expecting 16
  Calculator c;
  EXPECT_EQ(16, c.mult(8, 2));
}

TEST(TestCalculator, divTest) {
  // Divide 5 / 2, expecting near 2.5
  Calculator c;
  EXPECT_NEAR(2.5, c.div(5, 2), 0.0001);
}

TEST(TestCalculator, divByZeroTest) {
  // Divide (anything) / 0, expecting an error (div_by_zero_error)
  Calculator c;
  EXPECT_THROW(c.div(43, 0), div_by_zero_error);
}
