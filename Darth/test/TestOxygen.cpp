/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include "gtest/gtest.h"
#include "Oxygen.h"


TEST(TestOxygen, getSetOxygenLevel) {
  Oxygen o;
  int o2 = 15;
  o.setOxygenLevel(o2);

  EXPECT_EQ(o2, o.getOxygenLevel());
}

TEST(TestOxygen, tickOxygen) {
  Oxygen o;
  int o2 = 15;
  o.setOxygenLevel(o2);

  for (int i = 0; i < 7; i++)
    o.decrease(1);

  EXPECT_EQ(o.getOxygenLevel(), o2-7);
}

TEST(TestOxygen, increaseOxygen) {
  Oxygen o;
  int o2 = 3;
  int addo2 = 2;
  o.setOxygenLevel(o2);
  o.increase(addo2);

  EXPECT_EQ(o2+addo2, o.getOxygenLevel());
}

TEST(TestOxygen, oxygenRemains) {
  Oxygen o;
  o.setOxygenLevel(2);

  EXPECT_FALSE(o.decrease(1));
}

TEST(TestOxygen, noOxygen) {
  Oxygen o;
  o.setOxygenLevel(1);

  EXPECT_TRUE(o.decrease(1));
}

TEST(TestOxygen, setGetMaxOxygen) {
  Oxygen o;
  o.setMaxLevel(15);
  EXPECT_EQ(15, o.getMaxLevel());
}

TEST(TestOxygen, overflowMax) {
  Oxygen o;
  o.setMaxLevel(15);
  o.setOxygenLevel(13);
  o.increase(10);

  EXPECT_EQ(o.getMaxLevel(), o.getOxygenLevel());
}
