/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_INVENTORY_H_
#define INCLUDE_INVENTORY_H_

#include <vector>
#include <string>
#include "Item.h"

class Inventory {
 public:
  Inventory();
  virtual ~Inventory();

  /**
  * @return all items in the inventory.
  */
  std::vector<Item*>* getItems();

  /**
  * @param name the name of the item to look for
  * @return the item that is found
  * @throw unavailable_item_error if item is not found (To be determined)
  */
  Item* getItem(std::string name);

  /**
  * @param item the item to be added
  * @return whether the item was added or not (is the inv full?)
  */
  bool addItem(Item* item);

  /**
  * @param item the item to be removed
  * @return whether the item was removed (is the item there?)
  */
  bool removeItem(std::string name);

  /**
  * @return the number of items in the inventory
  */
  int getTotalItems();

  /**
  * @return the total number of items that can fit in this inventory
  */
  int getMaxItems();

 private:
  const int maxSize = 5;
  std::vector<Item*>* items;
};

#endif  // INCLUDE_INVENTORY_H_
