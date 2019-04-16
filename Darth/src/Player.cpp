/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <vector>
#include "Player.h"
#include "ItemType.h"
Player::Player() {
  quests = new QuestList();
  inventory = new Inventory();
  o2 = new Oxygen();
}

Player::~Player() {
  delete quests;
  delete inventory;
  delete o2;
}

Player::Player(Quest* starterQuest) {
  quests = new QuestList();
  inventory = new Inventory();
  o2 = new Oxygen();
  quests->addQuest(starterQuest);
}

Inventory* Player::getInventory() {
  return inventory;
}

QuestList* Player::getQuests() {
  return quests;
}

bool Player::useItem(Item* item, Room* room) {
  if (room->checkUsableItems(item->getName())) {
    if (item->getType() == ItemType::KEY)
      item->unlock();
    if (item->isReusable()) {
      return true;
    } else {
      inventory->removeItem(item->getName());
      return true;
    }
    return true;
  }
  if (item->getType() == ItemType::MAXOXYGENINCREASE
      || item->getType() == ItemType::OXYGENTANK) {
    inventory->removeItem(item->getName());
    return true;
  }
  if (item->getType() == ItemType::KEY) {
    for (int i = 0; i < room->getDoors()->size(); i++) {
      if (room->getDoors()->at(i) == item->getUnlock()) {
        item->unlock();
        inventory->removeItem(item->getName());
        return true;
      }
    }
  }
  return false;
}

Oxygen* Player::getOxygen() {
  return o2;
}

bool Player::getAlive() {
  return alive;
}

void Player::setAlive(bool st) {
  alive = st;
}

void Player::setStatus(StatusEffect effect) {
  this->effect = effect;
}

StatusEffect Player::getStatus() {
  return effect;
}

int Player::getStatusTime() {
  return effectTime;
}

void Player::setStatusTime(int tm) {
  effectTime = tm;
}

bool Player::tick() {
  bool out = false;

  Oxygen *o = o2;
  if (effect == StatusEffect::NONE)
    out = o->decrease(1);
  else if (effect == StatusEffect::COLD)
    out = o->decrease(2);
  else if (effect == StatusEffect::FIRE)
    out = o->decrease(3);
  else if (effect == StatusEffect::POISON)
    out = o->decrease(5);
  else if (effect == StatusEffect::ACID)
    out = o->decrease(7);
  else if (effect == StatusEffect::SEALING)
    out = o->decrease(effectTime);

  effectTime = effectTime - 1;
  if (effectTime <= 0) {
    if (effect == StatusEffect::COLD || effect == StatusEffect::SEALING) {
      effect = StatusEffect::NONE;
      effectTime = 0;
    } else if (effect != StatusEffect::COLD &&
               effect != StatusEffect::SEALING &&
               effect != StatusEffect::NONE) {
      if (effect == StatusEffect::ACID)
        effectTime = 4;
      else if (effect == StatusEffect::POISON)
        effectTime = 3;
      else if (effect == StatusEffect::FIRE)
        effectTime = 2;
      effect = StatusEffect::SEALING;
    } else {
      effect = StatusEffect::NONE;
    }
  }
  return out;
}

