/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include "gtest/gtest.h"
#include "Player.h"
#include "Observer.h"
#include "ButtonObserver.h"


// Constructor Testing
// consequently, this also tests "getSpec"
TEST(TestPlayer, ConstructorModel) {
  Player p(Model::B, Variant::A);
  EXPECT_EQ(Model::B, p.getSpec()->getModel());
}

TEST(TestPlayer, ConstructorVariant) {
  Player p(Model::B, Variant::D);
  EXPECT_EQ(Variant::D, p.getSpec()->getVariant());
}

// Command Testing
TEST(TestPlayer, PushModelT) {
  Player p(Model::T, Variant::A);
  p.pushButton(Button::D);
  EXPECT_EQ(Mode::RADIO, p.getSpec()->getMode());
}

TEST(TestPlayer, PushModelB) {
  Player p(Model::B, Variant::A);
  p.pushButton(Button::E);
  EXPECT_EQ(Mode::RADIO, p.getSpec()->getMode());
}

TEST(TestPlayer, PushModelM) {
  Player p(Model::M, Variant::A);
  p.pushButton(Button::A);
  EXPECT_EQ(Mode::RADIO, p.getSpec()->getMode());
}
