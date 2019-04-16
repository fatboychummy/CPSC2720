/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "Room.h"
#include "Door.h"
#include "Item.h"

// Just room stuff

TEST(TestRoom, hasNPC) {
  Room r;

  EXPECT_FALSE(r.hasNPC());
}

TEST(TestRoom, IDCounter) {
  Room r;
  Room r2;

  EXPECT_EQ(r2.getID(), r.getID() + 1);
}

TEST(TestRoom, ctrID) {
  Room r(15);

  EXPECT_EQ(15, r.getID());
}

TEST(TestRoom, info) {
  std::string info = "info";
  Room r;
  r.setRoomInfo(info);

  EXPECT_EQ(info, r.getRoomInfo());
}

TEST(TestRoom, searchInfo) {
  std::string sInfo = "sInfo";
  Room r;
  r.setSearchInfo(sInfo);

  EXPECT_EQ(sInfo, r.getSearchInfo());
}

TEST(TestRoom, name) {
  std::string name = "name";
  Room r;
  r.setRoomName(name);

  EXPECT_EQ(name, r.getRoomName());
}

// Room / Item stuff

TEST(TestRoom, addUseUsableItem) {
  std::string name = "name";
  Room r;
  Item *i = new Item(name, "info", false);

  r.addUsableItem(i);

  EXPECT_TRUE(r.checkUsableItems(name));
}

TEST(TestRoom, useUnusableItem) {
  std::string name = "name";
  Room r;
  Item *i = new Item(name, "info", false);

  EXPECT_FALSE(r.checkUsableItems(name));
  delete i;
}

TEST(TestRoom, addRemoveUsableItems) {
  Room r;
  std::string name = "name";
  Item *i = new Item(name, "alb", false);
  r.addUsableItem(i);
  r.removeUsableItem(name);

  EXPECT_FALSE(r.checkUsableItems(name));
}

TEST(TestRoom, addGetSearchItems) {
  Room r;
  std::string name = "name";
  Item *i = new Item(name, "info", false);
  r.addItem(i);

  EXPECT_EQ(i, r.getSearchItems()->at(0));
}

TEST(TestRoom, addRemoveSearchItems) {
  Room r;
  std::string name = "name";
  Item *i = new Item(name, "alb", false);
  r.addItem(i);
  r.removeItem(name);

  EXPECT_ANY_THROW(r.getSearchItems()->at(0)->getName());
}

// NPC stuff

TEST(TestRoom, createTalk) {
  NPC *n = new NPC("test", "testboi", "bla");
  Room r;
  r.setNPC(n);

  EXPECT_EQ("testboi", r.talkToNPC());
}

TEST(TestRoom, createTalk2) {
  NPC *n = new NPC("test", "testboi", "bla");
  Room *r = new Room();
  r->setNPC(n);
  r->talkToNPC();

  EXPECT_EQ("bla", r->talkToNPC());
  delete r;
}

/*TEST(DISABLED_TestRoom, DISABLED_questNPC) {
  std::string name = "name";
  std::string s1 = "s1";
  std::string s2 = "s2";
  std::string s3 = "s3";
  Quest *q = new Quest();
  q->setName("extorb");
  Item *i = new Item(name, s1, false);
  NPC *n = new NPC(name, s1, s2,
                s3, q, i);
  Room r;
  r.setNPC(n);
  EXPECT_EQ(name, r.getNPC()->getItem()->getName());
}*/

TEST(TestRoom, doorset) {
  std::vector<Door*>* doors = new std::vector<Door*>;
  Room *r = new Room();
  Room *r2 = new Room();
  Door *d = new Door(r->getID(), r2->getID());

  doors->push_back(d);
  r->setDoors(doors);

  EXPECT_EQ(r->getID(), r->getDoors()->at(0)->getRoomID1());

  delete r;
  delete r2;
}
