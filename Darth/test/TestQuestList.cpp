/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <string>
#include "gtest/gtest.h"
#include "Quest.h"
#include "QuestList.h"
#include "Exceptions.h"

TEST(TestQuestList, addFindQuest) {
  QuestList ql;
  Quest *q = new Quest();
  std::string name = "test";
  q->setName(name);
  q->setInfo("bla bla bla");
  ql.addQuest(q);

  EXPECT_EQ(q->getName(), ql.findQuest(name)->getName());
}

TEST(TestQuestList, completeQuest) {
  QuestList ql;
  Quest *q = new Quest();
  std::string name = "test";
  q->setName(name);
  q->setInfo("bla");

  ql.addQuest(q);
  ql.completeQuest(name);

  EXPECT_TRUE(ql.findQuest(name)->isCompleted());
}

TEST(TestQuestList, noFindQuestException) {
  QuestList ql;

  EXPECT_THROW(ql.findQuest("blabla"), unavailable_quest_error);
}

TEST(TestQuestList, getQuestPtr) {
  QuestList ql;
  Quest *q = new Quest();
  std::string name = "test";
  q->setName(name);
  q->setInfo("bla");

  ql.addQuest(q);
  Quest *q2 = ql.getQuests()->at(0);

  EXPECT_EQ(q, q2);
}
