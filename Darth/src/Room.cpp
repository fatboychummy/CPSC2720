/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <vector>
#include <string>
#include "Room.h"
#include "Puzzle.h"
#include "KeyPadPuzzle.h"
#include "Door.h"

int Room::lastID = 0;

Room::Room() {
  attachedDoors = new std::vector<Door*>;
  searchItems = new std::vector<Item*>;
  itemsUsableHere = new std::vector<Item*>;
  puzzle = nullptr;
  roomID = lastID;
  lastID += 1;
  npc = new NPC();
  hNPC = false;
  hPuzzle = false;
}

Room::Room(int ID) {
  attachedDoors = new std::vector<Door*>;
  searchItems = new std::vector<Item*>;
  itemsUsableHere = new std::vector<Item*>;
  puzzle = nullptr;
  roomID = ID;
  npc = new NPC();
  hNPC = false;
  hPuzzle = false;
}

Room::~Room() {
  /*
      std::vector<Door*> attachedDoors;
      std::vector<Item*> searchItems;
      std::vector<Item*> itemsUsableHere;
  */
  for (int i = 0; i < attachedDoors->size(); i++) {
    delete attachedDoors->at(i);
  }
  for (int i = 0; i < searchItems->size(); i++) {
    delete searchItems->at(i);
  }
  for (int i = 0; i < itemsUsableHere->size(); i++) {
    delete itemsUsableHere->at(i);
  }
  attachedDoors->clear();
  searchItems->clear();
  itemsUsableHere->clear();

  delete attachedDoors;
  delete searchItems;
  delete itemsUsableHere;
  delete npc;
  if (puzzle != nullptr)
    delete puzzle;
}

std::vector<Door*>* Room::getDoors() {
  return attachedDoors;
}

std::string Room::getRoomInfo() {
  return roomInfo;
}

std::string Room::getSearchInfo() {
  return searchInfo;
}

std::string Room::getRoomName() {
  return roomName;
}

void Room::setRoomName(std::string name) {
  this->roomName = name;
}


void Room::setRoomInfo(std::string info) {
  this->roomInfo = info;
}

void Room::setSearchInfo(std::string info) {
  searchInfo = info;
}

void Room::addItem(Item* item) {
  searchItems->push_back(item);
}

void Room::removeItem(std::string name) {
  for (int i = 0; i < searchItems->size(); i++) {
    if (searchItems->at(i)->getName() == name) {
      delete searchItems->at(i);
      searchItems->erase(searchItems->begin() + i);
    }
  }
}

void Room::resetLastID() {
  lastID = 0;
}

std::vector<Item*>* Room::getSearchItems() {
  return searchItems;
}

bool Room::hasNPC() {
  return hNPC;
}

std::string Room::talkToNPC() {
  return npc->talkTo();
}

NPC* Room::getNPC() {
  return npc;
}

void Room::setNPC(NPC* npc) {
  delete this->npc;
  hNPC = true;
  this->npc = npc;
}

int Room::getID() {
  return roomID;
}

void Room::addUsableItem(Item* item) {
  itemsUsableHere->push_back(item);
}

void Room::removeUsableItem(std::string name) {
  for (int i = 0; i < itemsUsableHere->size(); i++) {
    if (itemsUsableHere->at(i)->getName() == name) {
      delete itemsUsableHere->at(i);
      itemsUsableHere->erase(itemsUsableHere->begin() + i);
    }
  }
}

bool Room::checkUsableItems(std::string name) {
  for (int i = 0; i < itemsUsableHere->size(); i++) {
    if (itemsUsableHere->at(i)->getName() == name)
      return true;
  }
  return false;
}


void Room::setDoors(std::vector<Door*>* doorList) {
  delete attachedDoors;
  attachedDoors = doorList;
}

void Room::addDoor(Door* door) {
  attachedDoors->push_back(door);
}

// Puzzle stuff

Puzzle* Room::getPuzzle() {
  return puzzle;
}

void Room::setPuzzle(Puzzle* puzzle) {
  delete this->puzzle;
  hPuzzle = true;
  this->puzzle = puzzle;
}

bool Room::hasPuzzle() {
  return hPuzzle;
}

void Room::rmPuzzle() {
  hPuzzle = false;
}

