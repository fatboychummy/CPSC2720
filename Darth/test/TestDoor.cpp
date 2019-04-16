/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include "gtest/gtest.h"
#include "Door.h"

TEST(TestDoor, createGetRoom1) {
  Door d(1, 2, true);

  EXPECT_EQ(d.getRoomID1(), 1);
}

TEST(TestDoor, createGetRoom2) {
  Door d(1, 2, true);

  EXPECT_EQ(d.getRoomID2(), 2);
}

TEST(TestDoor, createGetLockStatus) {
  Door d(1, 2, true);

  EXPECT_TRUE(d.isLocked());
}

TEST(TestDoor, beforeDestroyOpenable) {
  Door d(1, 2, false);

  EXPECT_TRUE(d.canOpen());
}

TEST(TestDoor, destroyOpenable) {
  Door d(1, 2, true);
  d.destroy();

  EXPECT_FALSE(d.canOpen());
}

TEST(TestDoor, unlock) {
  Door d(1, 2, true);
  d.unlock();

  EXPECT_FALSE(d.isLocked());
}


