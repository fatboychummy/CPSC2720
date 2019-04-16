/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_NPC_H_
#define INCLUDE_NPC_H_

#include <string>
#include "Character.h"
#include "Quest.h"
#include "Item.h"

class NPC : public Character {
 public:
  /**
  * default constructor used by subclasses
  */
  NPC();

  /**
  * @param name the name of the npc
  * @param s1 the "first" speech of the npc
  * @param s2 the "second" speech of the npc
  * Example:
  * speech = "Hello, good sir."
  * speech2 = "Hello again, good sir."
  */
  NPC(std::string name, std::string s1, std::string s2);

  /**
  * @param name the name of the npc
  * @param s1 the "first" speech of the npc
  * @param s2 the "second" speech of the npc
  * @param s3 the "third" speech of the npc (only used if questGiver)
  * @param questGiven the quest the player is given (only used if questGiver)
  * @param itemGiven the item the player is rewarded after completing the quest. (Only used if questGiver)
  * @param itemTakes the item the NPC takes in exchange for the NPC's item. (Only used if questGiver)
  * Example:
  * speech = "Hello, good sir."
  * speech2 = "Hello again, good sir, did you finish my quest?."
  * speech3 = "Thank you for completing x"
  */
  NPC(std::string name, std::string s1, std::string s2,
      std::string s3, Quest* questGiven,
      Item* itemGiven, Item* itemTakes);
  virtual ~NPC();

  /**
  * this function sets hasSpoken to true.
  * if hasSpoken is false, say speech, else say speech2
  * if givenItem is true, say speech3
  * @return a string that the NPC says
  */
  std::string talkTo();

  /**
  * kept for compatibility between rooms;  Need to figure out a better
  * way to do this in fix phase.
  * @return the item the npc is holding (to give to player)
  */
  Item* getItem();

  /**
  * kept for compatibility between rooms;  Need to figure out a better
  * way to do this in fix phase.
  * @return the quest the npc has (to give to player)
  */
  Quest* getQuest();

  /**
  * @return if the npc has a quest
  */
  bool isQuester();

  /**
  * @return if the npc has given the player the quest
  */
  bool hasGivenQuest();

  /**
  * @param set the boolean value to set givenQuest to
  */
  void setGQuest(bool set);

  /**
  * @return if the npc has given the player the item
  */
  bool hasGivenItem();

  /**
  * @return the item the NPC takes in exchange for his item
  */
  Item* getTakenItem();

 private:
  Item* holding;
  Item* takes;
  Quest* questGiven;
  std::string speech;
  std::string speech2;
  std::string speech3;
  bool hasSpoken = false;
  bool givenItem = false;
  bool givenQuest = false;
  bool isQuest;
};

#endif  // INCLUDE_NPC_H_
