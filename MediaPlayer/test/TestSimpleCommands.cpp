/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include "gtest/gtest.h"
#include "PlayCommand.h"
#include "PauseCommand.h"
#include "PreviousCommand.h"
#include "NextCommand.h"
#include "ModeCommand.h"

// MP3
TEST(TestSimpleCommands, MP3Play) {
  Player *p = new Player(Model::B, Variant::A);
  PlayCommand c(p);
  EXPECT_NO_FATAL_FAILURE(c.go());

  delete p;
}

TEST(TestSimpleCommands, MP3Pause) {
  Player *p = new Player(Model::B, Variant::A);
  PauseCommand c(p);
  EXPECT_NO_FATAL_FAILURE(c.go());

  delete p;
}

TEST(TestSimpleCommands, MP3Previous) {
  Player *p = new Player(Model::B, Variant::A);
  PreviousCommand c(p);
  EXPECT_NO_FATAL_FAILURE(c.go());

  delete p;
}

TEST(TestSimpleCommands, MP3Next) {
  Player *p = new Player(Model::B, Variant::A);
  NextCommand c(p);
  EXPECT_NO_FATAL_FAILURE(c.go());

  delete p;
}


// RADIO
TEST(TestSimpleCommands, RADIOPlay) {
  Player *p = new Player(Model::B, Variant::A);
  PlayCommand c(p);
  ModeCommand m(p);
  m.go();
  EXPECT_NO_FATAL_FAILURE(c.go());

  delete p;
}

TEST(TestSimpleCommands, RADIOPause) {
  Player *p = new Player(Model::B, Variant::A);
  PauseCommand c(p);
  ModeCommand m(p);
  m.go();
  EXPECT_NO_FATAL_FAILURE(c.go());

  delete p;
}

TEST(TestSimpleCommands, RADIOPrevious) {
  Player *p = new Player(Model::B, Variant::A);
  PreviousCommand c(p);
  ModeCommand m(p);
  m.go();
  EXPECT_NO_FATAL_FAILURE(c.go());

  delete p;
}

TEST(TestSimpleCommands, RADIONext) {
  Player *p = new Player(Model::B, Variant::A);
  NextCommand c(p);
  ModeCommand m(p);
  m.go();
  EXPECT_NO_FATAL_FAILURE(c.go());

  delete p;
}


// VIDEO
TEST(TestSimpleCommands, VIDEOPlay) {
  Player *p = new Player(Model::B, Variant::A);
  PlayCommand c(p);
  ModeCommand m(p);
  m.go();
  m.go();
  EXPECT_NO_FATAL_FAILURE(c.go());

  delete p;
}

TEST(TestSimpleCommands, VIDEOPause) {
  Player *p = new Player(Model::B, Variant::A);
  PauseCommand c(p);
  ModeCommand m(p);
  m.go();
  m.go();
  EXPECT_NO_FATAL_FAILURE(c.go());

  delete p;
}

TEST(TestSimpleCommands, VIDEOPrevious) {
  Player *p = new Player(Model::B, Variant::A);
  PreviousCommand c(p);
  ModeCommand m(p);
  m.go();
  m.go();
  EXPECT_NO_FATAL_FAILURE(c.go());

  delete p;
}

TEST(TestSimpleCommands, VIDEONext) {
  Player *p = new Player(Model::B, Variant::A);
  NextCommand c(p);
  ModeCommand m(p);
  m.go();
  m.go();
  EXPECT_NO_FATAL_FAILURE(c.go());

  delete p;
}
