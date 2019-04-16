/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_SHIP_H_
#define INCLUDE_SHIP_H_

#include <vector>
#include "Door.h"
#include "Player.h"
#include "Room.h"

class Ship {
 public:
  Ship();
  virtual ~Ship();

  /**
  * @param door the door to be moved through
  * @return if the player moved through the door or not.
  */
  bool moveThroughDoor(Door *door);

  /**
  * @return the player associated with the ship.
  */
  Player* getPlayer();

  /**
  * @return the current room the player is in.
  */
  Room* getCurrentRoom();

  /**
  * @return the vector of all the current rooms.
  */
  std::vector<Room*>* getRooms();

  /**
  * @param rooms the vector of all the current rooms.
  */
  void setRooms(std::vector<Room*>* rooms);

  /**
  * @param player the player to be associated with the game
  */
  void setPlayer(Player* player);

  /**
  * @param room the room that the player should currently be in.
  */
  void setCurrentRoom(Room* room);

 private:
  std::vector<Room*>* allRooms;
  Room* currentRoom;
  Player* player;
};

#endif  // INCLUDE_SHIP_H_
