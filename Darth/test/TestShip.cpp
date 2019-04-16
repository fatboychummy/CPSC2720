/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "Ship.h"

TEST(TestShip, setGetPlayer) {
  std::string name = "nom";
  Player *p = new Player();
  p->setName(name);
  Ship ship;

  ship.setPlayer(p);

  EXPECT_EQ(name, ship.getPlayer()->getName());
}

TEST(TestShip, setGetCurrentRoom) {
  std::string name = "cRoom";
  Room *r = new Room();
  r->setRoomName(name);
  Ship ship;
  ship.setCurrentRoom(r);

  EXPECT_EQ(name, ship.getCurrentRoom()->getRoomName());

  delete r;
}

TEST(TestShip, moveBetweenRoomsCan) {
  Room *r = new Room();
  Room *r2 = new Room();
  Door *d = new Door(r->getID(), r2->getID());
  std::vector<Door*>* doors = new std::vector<Door*>;
  doors->push_back(d);
  r->setDoors(doors);

  Ship ship;
  std::vector<Room*>* rooms = new std::vector<Room*>;
  rooms->push_back(r);
  rooms->push_back(r2);
  ship.setRooms(rooms);
  ship.setCurrentRoom(r);

  EXPECT_TRUE(ship.moveThroughDoor(d));
}

TEST(TestShip, moveBetweenRoomsCan2) {
  Room *r = new Room();
  Room *r2 = new Room();
  Door *d = new Door(r2->getID(), r->getID());
  std::vector<Door*>* doors = new std::vector<Door*>;
  doors->push_back(d);
  r->setDoors(doors);

  Ship ship;
  std::vector<Room*>* rooms = new std::vector<Room*>;
  rooms->push_back(r);
  rooms->push_back(r2);
  ship.setRooms(rooms);
  ship.setCurrentRoom(r);

  EXPECT_TRUE(ship.moveThroughDoor(d));
}

TEST(TestShip, moveBetweenRoomsCant) {
  Room *r = new Room();
  Room *r2 = new Room();
  Door *d = new Door(r->getID(), 1000);
  std::vector<Door*>* doors = new std::vector<Door*>;
  doors->push_back(d);
  r->setDoors(doors);

  Ship ship;
  std::vector<Room*>* rooms = new std::vector<Room*>;
  rooms->push_back(r);
  ship.setRooms(rooms);
  ship.setCurrentRoom(r);

  EXPECT_FALSE(ship.moveThroughDoor(d));

  delete r2;
}

TEST(TestShip, moveBetweenRoomsCant2) {
  Room *r = new Room();
  Room *r2 = new Room();
  Door *d = new Door(1001, 1000);
  std::vector<Door*>* doors = new std::vector<Door*>;
  doors->push_back(d);
  r->setDoors(doors);

  Ship ship;
  std::vector<Room*>* rooms = new std::vector<Room*>;
  rooms->push_back(r);
  ship.setRooms(rooms);
  ship.setCurrentRoom(r);

  EXPECT_FALSE(ship.moveThroughDoor(d));

  delete r2;
}



TEST(TestShip, setGetRooms) {
  Room *r = new Room();
  std::string name = "noo";
  r->setRoomName(name);
  std::vector<Room*>* rooms = new std::vector<Room*>;
  rooms->push_back(r);
  Ship ship;
  ship.setRooms(rooms);

  EXPECT_EQ(name, ship.getRooms()->at(0)->getRoomName());
}
