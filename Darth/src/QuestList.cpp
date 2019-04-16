/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <vector>
#include <string>
#include "QuestList.h"
#include "Exceptions.h"

QuestList::QuestList() {
  quests = new std::vector<Quest*>;
}

QuestList::~QuestList() {
  for (int i = 0; i < quests->capacity(); i++) {
    delete quests->at(i);   // delet every item in the vector
  }
  quests->clear();  // delete the pointers
  delete quests;
}

std::vector<Quest*>* QuestList::getQuests() {
  return quests;
}

Quest* QuestList::findQuest(std::string name) {
  for (int i = 0; i < quests->size(); i++) {
    if (quests->at(i)->getName() == name)
      return quests->at(i);
  }
  throw unavailable_quest_error("That quest does not exist");
  // o h   n o   t h e   q u e s t   d o e s n ' t   e x i s t
}


void QuestList::addQuest(Quest* quest) {
  quests->push_back(quest);
}

void QuestList::completeQuest(std::string qName) {
  this->findQuest(qName)->completeQuest();
}
