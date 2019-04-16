/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include "Character.h"
#include "Inventory.h"
#include "QuestList.h"
#include "Room.h"
#include "Item.h"
#include "Oxygen.h"
#include "StatusEffect.h"

class Player : public Character {
 public:
  /**
  * Only use the default constructor if there is no starter quest.
  */
  Player();

  /**
  * @param starterQuest the quest to give the player upon starting the game.
  */
  explicit Player(Quest* starterQuest);
  virtual ~Player();

  /**
  * @return the player's inventory.
  */
  Inventory* getInventory();

  /**
  * @return the player's quests.
  */
  QuestList* getQuests();

  /**
  * @return if the item was able to be used or not.
  */
  bool useItem(Item* item, Room* room);


  /**
  * @return the player's oxygen object.
  */
  Oxygen* getOxygen();

  /**
  * @return if the player is still alive
  */
  bool getAlive();

  /**
  * @param st player's alive status
  */
  void setAlive(bool st);

  /**
  * @param effect the status effect to add to the player
  */
  void setStatus(StatusEffect effect);

  /**
  * @return the current status effect affecting the player
  */
  StatusEffect getStatus();

  /**
  * @return the current status effect time left
  */
  int getStatusTime();

  /**
  * @param tm the time to set until the status effect expires
  */
  void setStatusTime(int tm);

  /**
  * @return if the player dies of oxygen loss
  */
  bool tick();

 private:
  Inventory* inventory;
  QuestList* quests;
  Oxygen* o2;
  bool alive = true;
  StatusEffect effect = StatusEffect::NONE;
  int effectTime = 0;
};

#endif  // INCLUDE_PLAYER_H_
