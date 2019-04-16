/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <string>
#include "gtest/gtest.h"
#include "Quest.h"

TEST(TestQuest, setGetInfo) {
  Quest q;
  std::string info = "test";
  q.setInfo(info);

  EXPECT_EQ(q.getInfo(), info);
}

TEST(TestQuest, setGetName) {
  Quest q;
  std::string name = "test";
  q.setName(name);

  EXPECT_EQ(q.getName(), name);
}

TEST(TestQuest, noComplete) {
  Quest q;

  EXPECT_FALSE(q.isCompleted());
}

TEST(TestQuest, complete) {
  Quest q;
  q.completeQuest();

  EXPECT_TRUE(q.isCompleted());
}
