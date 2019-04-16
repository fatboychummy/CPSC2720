/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <string>
#include "gtest/gtest.h"
#include "NPC.h"

TEST(TestNPC, setGetName) {
  NPC n;
  std::string name = "name";
  n.setName(name);

  EXPECT_EQ(n.getName(), name);
}

TEST(TestNPC, setGetNameCtr) {
  std::string name = "name";
  NPC n(name, "bla", "bla");

  EXPECT_EQ(n.getName(), name);
}

// Quest Giver Stuff

/*TEST(DISABLED_TestNPC, DISABLED_getItem) {
  std::string name = "name";
  std::string s1 = "s1";
  std::string s2 = "s2";
  std::string s3 = "s3";
  std::string qName = "qName";
  std::string iName = "iName";
  Quest *q = new Quest();
  q->setName(qName);
  Item *i = new Item(iName, "info", false);

  NPC *n = new NPC(name, s1, s2,
                  s3, q, i);

  EXPECT_EQ(n->getItem(), i);
  delete n;
}

TEST(DISABLED_TestNPC, DISABLED_getQuest) {
  std::string name = "name";
  std::string s1 = "s1";
  std::string s2 = "s2";
  std::string s3 = "s3";
  std::string qName = "qName";
  std::string iName = "iName";
  Quest *q = new Quest();
  q->setName(qName);
  Item *i = new Item(iName, "info", false);

  NPC *n = new NPC(name, s1, s2,
                  s3, q, i);

  EXPECT_EQ(n->getQuest(), q);
  delete n;
}

TEST(DISABLED_TestNPC, DISABLED_speak1) {
  std::string name = "name";
  std::string s1 = "s1";
  std::string s2 = "s2";
  std::string s3 = "s3";
  std::string qName = "qName";
  std::string iName = "iName";
  Quest *q = new Quest();
  q->setName(qName);
  Item *i = new Item(iName, "info", false);

  NPC *n = new NPC(name, s1, s2,
                  s3, q, i);

  EXPECT_EQ(s1, n->talkTo());
  delete n;
}

TEST(DISABLED_TestNPC, DISABLED_speak2) {
  std::string name = "name";
  std::string s1 = "s1";
  std::string s2 = "s2";
  std::string s3 = "s3";
  std::string qName = "qName";
  std::string iName = "iName";
  Quest *q = new Quest();
  q->setName(qName);
  Item *i = new Item(iName, "info", false);

  NPC *n = new NPC(name, s1, s2,
                  s3, q, i);

  n->talkTo();
  EXPECT_EQ(s2, n->talkTo());
  delete n;
}

TEST(DISABLED_TestNPC, DISABLED_speak3) {
  std::string name = "name";
  std::string s1 = "s1";
  std::string s2 = "s2";
  std::string s3 = "s3";
  std::string qName = "qName";
  std::string iName = "iName";
  Quest *q = new Quest();
  q->setName(qName);
  Item *i = new Item(iName, "info", false);

  NPC *n = new NPC(name, s1, s2,
                  s3, q, i);

  Item *b = n->getItem();
  EXPECT_EQ(s3, n->talkTo());
  delete n;
}
*/
