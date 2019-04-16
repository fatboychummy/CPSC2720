/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_QUESTLIST_H_
#define INCLUDE_QUESTLIST_H_

#include <vector>
#include <string>
#include "Quest.h"

class QuestList {
 public:
  QuestList();
  virtual ~QuestList();

  /**
  * @return the quests in the list
  */
  std::vector<Quest*>* getQuests();

  /**
  * @param name the name of the quest to find
  * @return the quest found
  * @throw unavailable_quest_error if quest is not on the list
  */
  Quest* findQuest(std::string name);

  /**
  * @param quest the quest to add
  */
  void addQuest(Quest* quest);

  /**
  * calls the Quest's `completeQuest'
  * @param qName the name of the quest to complete
  */
  void completeQuest(std::string qName);

 private:
  std::vector<Quest*>* quests;
};

#endif  // INCLUDE_QUESTLIST_H_
