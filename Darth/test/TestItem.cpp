/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <string>
#include "gtest/gtest.h"
#include "Item.h"

TEST(TestItem, ctorName) {
  std::string name = "test";
  Item i = Item(name, "bla", true, 1);

  EXPECT_EQ(i.getName(), name);
}

TEST(TestItem, ctorInfo) {
  std::string info = "test";
  Item i = Item("bla", info, true, 1);

  EXPECT_EQ(i.getInfo(), info);
}

TEST(TestItem, ctorReuse) {
  Item i = Item("bla", "bla", true, 1);

  EXPECT_TRUE(i.isReusable());
}

TEST(TestItem, ctorCount) {
  int count = 12;
  Item i = Item("bla", "bla", true, count);

  EXPECT_EQ(i.getCount(), count);
}
