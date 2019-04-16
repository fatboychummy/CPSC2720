/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_ROOM_H_
#define INCLUDE_ROOM_H_

#include <vector>
#include <string>
#include "Door.h"
#include "Item.h"
#include "NPC.h"
#include "Puzzle.h"

class Room {
 public:
  /**
  * Used for the initial creation of rooms
  */
  Room();

  /**
  * Used for simplicity when saving/loading
  * @param ID integer to be used to quickly "differentiate" between rooms.
  */
  explicit Room(int ID);
  virtual ~Room();

  /**
   * @return a vector of pointers to the doors attached to this room.
   */
  std::vector<Door*>* getDoors();

  /**
  * @return the room's information string (what is said upon entering the room)
  */
  std::string getRoomInfo();

  /**
  * @return the room's search information (what is said when the room is searched)
  */
  std::string getSearchInfo();

  /**
  * @return the name of the room.
  */
  std::string getRoomName();

  /**
  * @param name the name of the room
  */
  void setRoomName(std::string name);

  /**
  * @param doorList a list of doors that are attached to this room.
  */
  void setDoors(std::vector<Door*>* doorList);

  /**
  * @param door the door to add to the room
  */
  void addDoor(Door* door);

  /**
  * @param info the room's information string (what is said upon entering)
  */
  void setRoomInfo(std::string info);

  /**
  * @param info the room's search information (what is said upon searching)
  */
  void setSearchInfo(std::string info);

  /**
  * @param item add a single item to the room.
  */
  void addItem(Item* item);

  /**
  * @param name name of item to remove.
  */
  void removeItem(std::string name);

  /**
  * Resets the ID counter so that rooms work properly.
  */
  void resetLastID();

  /**
  * @return a vector of items in the room the player can acquire.
  */
  std::vector<Item*>* getSearchItems();

  /**
  * @return if the room contains an NPC
  */
  bool hasNPC();

  /**
  * @return what the NPC says.
  */
  std::string talkToNPC();

  /**
  * @return the npc in the room.
  */
  NPC* getNPC();

  /**
  * @return the puzzle
  */
  Puzzle* getPuzzle();

  /**
  * @param puzzle the puzzle to set for the room.
  */
  void setPuzzle(Puzzle* puzzle);

  /**
  * @return whether the room has a puzzle or not.
  */
  bool hasPuzzle();

  /**
  * sets hPuzzle to false (if puzzle is complete, puzzle is gone)
  */
  void rmPuzzle();

  /**
  * This method will set hNPC to true, and set this.npc to npc
  * @param npc the npc to insert into the room
  */
  void setNPC(NPC* npc);

  /**
  * @return the ID of the room.
  */
  int getID();

  /**
  * @param item the item that is usable here
  */
  void addUsableItem(Item* item);

  /**
  * removes an item from the usable items list, making it so
  * you can't use an item twice.
  * @param name the name of the item to check for
  */
  void removeUsableItem(std::string name);

  /**
  * @param name the name of the item to check for
  * @return if the item is usable or not
  */
  bool checkUsableItems(std::string name);

 private:
  static int lastID;
  int roomID;
  std::vector<Door*>* attachedDoors;
  std::vector<Item*>* searchItems;
  std::vector<Item*>* itemsUsableHere;
  std::string roomName;
  std::string roomInfo;
  std::string searchInfo;
  bool hNPC;
  bool hPuzzle;
  NPC* npc;
  Puzzle* puzzle;
};

#endif  // INCLUDE_ROOM_H_
