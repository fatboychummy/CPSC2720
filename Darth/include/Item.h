/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_ITEM_H_
#define INCLUDE_ITEM_H_

#include <string>
#include <vector>
#include "ItemType.h"
#include "Door.h"


class Item {
 public:
  /**
  * @param name the name of the item
  * @param info the information on the item
  * @param reusable if the item can be used more than once
  * @param count how many of the item the player has
  */
  Item(std::string name, std::string info,
       bool reusable, int count = 1);
  virtual ~Item();



  /**
  * @return the name of the item
  */
  std::string getName();

  /**
  * @return the information on the item
  */
  std::string getInfo();

  void setInfo(std::string info);

  /**
  * @return if the item is reusable
  */
  bool isReusable();

  /**
  * @return the amount of the item the player is holding
  */
  int getCount();

  /**
  * @param type the type of item this is
  */
  void setType(ItemType type);

  /**
  * @return the type of item this is
  */
  ItemType getType();

  /**
  * Unlocks a door this is connected to
  * (Only works if type == KEY)
  */
  void unlock();

  /**
  * @return the door that this key unlocks
  */
  Door* getUnlock();

  /**
  * @param door the door to unlock if item is a key
  */
  void setUnlock(Door* door);

 private:
  std::string name;
  std::string info;
  bool reusable;
  int count;
  ItemType type;
  Door* unlocks;
};

#endif  // INCLUDE_ITEM_H_
