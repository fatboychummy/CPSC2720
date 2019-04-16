/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <string>
#include "NPC.h"
#include "Exceptions.h"
NPC::NPC() {
  questGiven = new Quest();
  holding = new Item("placeholder", "placeholder", false);
  givenItem = false;
  isQuest = false;
}

NPC::NPC(std::string name, std::string s1, std::string s2) {
  questGiven = new Quest();
  holding = new Item("placeholder", "placeholder", false);
  setName(name);
  speech = s1;
  speech2 = s2;
  isQuest = false;
}

NPC::NPC(std::string name, std::string s1, std::string s2, std::string s3,
         Quest* questGiven, Item* itemGiven, Item* itemTakes) {
  this->questGiven = questGiven;
  this->holding = itemGiven;
  this->takes = itemTakes;
  setName(name);
  speech = s1;
  speech2 = s2;
  speech3 = s3;
  isQuest = true;
}

NPC::~NPC() {
  if (!givenQuest)
    delete questGiven;
  if (!givenItem)
    delete holding;
  if (givenItem)
    delete takes;
}

std::string NPC::talkTo() {
  /*
  * this function sets hasSpoken to true.
  * if hasSpoken is false, say speech, else say speech2
  * if givenItem is true, say speech3
  */
  if (givenItem)
    return speech3;
  else if (hasSpoken)
    return speech2;
  hasSpoken = true;
  return speech;
}

Item* NPC::getItem() {
  givenItem = true;
  questGiven->completeQuest();
  return holding;
}

Quest* NPC::getQuest() {
  return questGiven;
}

bool NPC::isQuester() {
  return isQuest;
}

bool NPC::hasGivenQuest() {
  return givenQuest;
}

bool NPC::hasGivenItem() {
  return givenItem;
}

void NPC::setGQuest(bool set) {
  givenQuest = set;
}

Item* NPC::getTakenItem() {
  return takes;
}


