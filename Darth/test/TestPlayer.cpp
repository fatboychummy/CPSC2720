/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <string>
#include "gtest/gtest.h"
#include "Player.h"
#include "Room.h"
#include "Quest.h"
#include "QuestList.h"
#include "ItemType.h"

TEST(TestPlayer, setGetName) {
  Player p;
  std::string name = "Alvin";
  p.setName(name);

  EXPECT_EQ(p.getName(), name);
}



TEST(TestPlayer, addStartGetQuest) {
  std::string name = "name";
  Quest *q = new Quest();
  q->setName(name);
  Player p(q);

  EXPECT_EQ(p.getQuests()->findQuest(name), q);
}

TEST(TestPlayer, getInv) {
  Player p;
  p.setName("Little Johnny");

  EXPECT_TRUE(p.getInventory() != nullptr);
}

TEST(TestPlayer, useItemNoGoodRoom) {
  Player p;
  Item *i = new Item("test", "this is", false);
  Item *i2 = new Item("test2", "this is another", false);
  Room *r = new Room();
  r->addUsableItem(i2);
  i->setType(ItemType::USELESS);

  EXPECT_FALSE(p.useItem(i, r));
  delete r;
  delete i;
  // delete i2;
}

TEST(TestPlayer, useItemGoodRoom) {
  Player p;
  Item *i = new Item("test", "this is", false);
  Room *r = new Room();
  r->addUsableItem(i);
  i->setType(ItemType::USELESS);

  EXPECT_TRUE(p.useItem(i, r));
  delete r;
}

TEST(TestPlayer, oxygen) {
  Player p;
  Oxygen *o = p.getOxygen();

  EXPECT_NO_THROW(o->increase(5));
}
