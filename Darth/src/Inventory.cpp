/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <string>
#include <vector>
#include "Inventory.h"
#include "Exceptions.h"

Inventory::Inventory() {
  items = new std::vector<Item*>;
  items->reserve(5);
}

Inventory::~Inventory() {
  for (int i = 0; i < items->size(); i++) {
    delete items->at(i);
  }
  items->clear();
  delete items;
}

std::vector<Item*>* Inventory::getItems() {
  return items;
}

Item* Inventory::getItem(std::string name) {
  for (int i = 0; i < items->size(); i++) {
    if (items->at(i)->getName() == name)
      return items->at(i);
  }
  throw unavailable_item_error("Could not find item");
}

bool Inventory::addItem(Item* item) {
  if (items->size() >= 5)
    return false;
  items->push_back(item);
  return true;
}

bool Inventory::removeItem(std::string name) {
  for (int i = 0; i < items->size(); i++) {
    if (items->at(i)->getName() == name) {
      items->erase(items->begin() + i);
      return true;
    }
  }
  return false;
}

int Inventory::getTotalItems() {
  return items->size();
}

int Inventory::getMaxItems() {
  return maxSize;
}
