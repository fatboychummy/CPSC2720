/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_DOOR_H_
#define INCLUDE_DOOR_H_

class Door {
 public:
  /**
  * @param cRoom1 one room this door connects to.
  * @param cRoom2 the other room this door connects to.
  * @param locked if the door is locked or not.
  */
  Door(int cRoom1, int cRoom2, bool locked = false);
  virtual ~Door();

  /**
  * unlocks a door, does nothing to an already unlocked door.
  */
  void unlock();

  /**
  * @return if the door can open or not.
  */
  bool canOpen();

  /**
  * @return if the door is locked.
  */
  bool isLocked();

  /**
  * @return room 1's ID
  */
  int getRoomID1();

  /**
  * @return room 2's ID
  */
  int getRoomID2();

  /**
  * "destroys" a door, making it so that the door is no longer openable (openable -> false)
  */
  void destroy();

 private:
  bool locked;
  bool openable;
  int r1;
  int r2;
};

#endif  // INCLUDE_DOOR_H_
