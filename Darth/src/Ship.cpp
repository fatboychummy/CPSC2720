/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <vector>
#include "Ship.h"

Ship::Ship() {
  player = new Player();
  currentRoom = new Room();
  allRooms = new std::vector<Room*>;
  allRooms->push_back(currentRoom);
}

Ship::~Ship() {
  for (int i = 0; i < allRooms->capacity(); i++) {
    delete allRooms->at(i);
  }
  allRooms->clear();

  delete allRooms;
  delete player;
}

bool Ship::moveThroughDoor(Door* door) {
  int cID = currentRoom->getID();
  int toID = -1;
  if (cID == door->getRoomID1())
    toID = door->getRoomID2();
  else if (cID == door->getRoomID2())
    toID = door->getRoomID1();
  else
    return false;

  if (!door->canOpen())
    return false;

  for (int i = 0; i < allRooms->size(); i++) {
    if (toID == allRooms->at(i)->getID()) {
      currentRoom = allRooms->at(i);
      return true;
    }
  }
  return false;
}

Player* Ship::getPlayer() {
  return player;
}

Room* Ship::getCurrentRoom() {
  return currentRoom;
}

std::vector<Room*>* Ship::getRooms() {
  return allRooms;
}

void Ship::setRooms(std::vector<Room*>* rooms) {
  for (int i = 0; i < allRooms->size(); i++) {
    delete allRooms->at(i);
  }
  allRooms->clear();
  delete allRooms;
  allRooms = rooms;
  this->currentRoom = allRooms->at(0);
}

void Ship::setPlayer(Player* player) {
  delete this->player;
  this->player = player;
}

void Ship::setCurrentRoom(Room* room) {
  this->currentRoom = room;
}
