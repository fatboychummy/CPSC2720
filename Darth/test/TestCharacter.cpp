/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <string>
#include "gtest/gtest.h"
#include "Character.h"

TEST(TestCharacter, setGetName) {
  Character c;
  std::string name = "name";
  c.setName(name);

  EXPECT_EQ(c.getName(), name);
}
