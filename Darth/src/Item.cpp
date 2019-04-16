/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <string>
#include "Item.h"
#include "Door.h"

Item::Item(std::string name, std::string info, bool reusable, int count) {
  this->name = name;
  this->info = info;
  this->reusable = reusable;
  this->count = count;
  type = ItemType::USELESS;
}

std::string Item::getName() {
  return name;
}

std::string Item::getInfo() {
  return info;
}

bool Item::isReusable() {
  return reusable;
}

int Item::getCount() {
  return count;
}

void Item::setInfo(std::string info) {
  this->info = info;
}

void Item::setType(ItemType type) {
  this->type = type;
}

ItemType Item::getType() {
  return type;
}

void Item::unlock() {
  if (type == ItemType::KEY)
    unlocks->unlock();
}

void Item::setUnlock(Door* door) {
  unlocks = door;
}

Door* Item::getUnlock() {
  return unlocks;
}


Item::~Item() {
}
