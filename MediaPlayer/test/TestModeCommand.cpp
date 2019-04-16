/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include "gtest/gtest.h"
#include "Player.h"
#include "ModeCommand.h"

TEST(TestModeCommand, OlSwapperoo) {
  Player *p = new Player(Model::B, Variant::A);
  ModeCommand m(p);
  m.go();
  EXPECT_EQ(Mode::RADIO, p->getSpec()->getMode());

  delete p;
}
