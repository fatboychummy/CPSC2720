/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include "gtest/gtest.h"
#include "Player.h"
#include "ButtonObserver.h"
#include "Exceptions.h"

// Observer Testing

TEST(TestObserver, Attach) {
  Player *p = new Player(Model::B, Variant::D);
  EXPECT_NO_FATAL_FAILURE(ButtonObserver b(p));

  delete p;
}

TEST(TestObserver, Remove) {
  Player *p = new Player(Model::B, Variant::D);
  ButtonObserver b(p);
  EXPECT_NO_FATAL_FAILURE(p->delObserver(&b));

  delete p;
}

// Counters
TEST(TestObserver, CountA) {
  Player *p = new Player(Model::T, Variant::A);
  ButtonObserver b(p);
  for (int i = 0; i < 5; i++)
    b.notify(NotificationType::BUTTON, "A");
  EXPECT_EQ(5, b.getPushes()[Button::A]);

  delete p;
}

TEST(TestObserver, CountB) {
  Player *p = new Player(Model::T, Variant::A);
  ButtonObserver b(p);
  for (int i = 0; i < 5; i++)
    b.notify(NotificationType::BUTTON, "B");
  EXPECT_EQ(5, b.getPushes()[Button::B]);

  delete p;
}

TEST(TestObserver, CountC) {
  Player *p = new Player(Model::T, Variant::A);
  ButtonObserver b(p);
  for (int i = 0; i < 5; i++)
    b.notify(NotificationType::BUTTON, "C");
  EXPECT_EQ(5, b.getPushes()[Button::C]);

  delete p;
}

TEST(TestObserver, CountD) {
  Player *p = new Player(Model::T, Variant::A);
  ButtonObserver b(p);
  for (int i = 0; i < 5; i++)
    b.notify(NotificationType::BUTTON, "D");
  EXPECT_EQ(5, b.getPushes()[Button::D]);

  delete p;
}

TEST(TestObserver, CountE) {
  Player *p = new Player(Model::T, Variant::A);
  ButtonObserver b(p);
  for (int i = 0; i < 5; i++)
    b.notify(NotificationType::BUTTON, "E");
  EXPECT_EQ(5, b.getPushes()[Button::E]);

  delete p;
}

TEST(TestObserver, CountErrorInvalidLength) {
  Player *p = new Player(Model::T, Variant::A);
  ButtonObserver b(p);
  EXPECT_THROW(b.notify(NotificationType::BUTTON, "AB"),
                invalid_observer_format_error);

  delete p;
}

TEST(TestObserver, CountErrorInvalidButton) {
  Player *p = new Player(Model::T, Variant::A);
  ButtonObserver b(p);
  EXPECT_THROW(b.notify(NotificationType::BUTTON, "Z"),
                invalid_observer_format_error);

  delete p;
}

TEST(TestObserver, PlayerNotifyUsA) {
  Player *p = new Player(Model::T, Variant::A);
  ButtonObserver b(p);
  for (int i = 0; i < 5; i++)
    p->pushButton(Button::A);
  EXPECT_EQ(5, b.getPushes()[Button::A]);

  delete p;
}

TEST(TestObserver, PlayerNotifyUsB) {
  Player *p = new Player(Model::T, Variant::A);
  ButtonObserver b(p);
  for (int i = 0; i < 5; i++)
    p->pushButton(Button::B);
  EXPECT_EQ(5, b.getPushes()[Button::B]);

  delete p;
}

TEST(TestObserver, PlayerNotifyUsC) {
  Player *p = new Player(Model::T, Variant::A);
  ButtonObserver b(p);
  for (int i = 0; i < 5; i++)
    p->pushButton(Button::C);
  EXPECT_EQ(5, b.getPushes()[Button::C]);

  delete p;
}

TEST(TestObserver, PlayerNotifyUsD) {
  Player *p = new Player(Model::T, Variant::A);
  ButtonObserver b(p);
  for (int i = 0; i < 5; i++)
    p->pushButton(Button::D);
  EXPECT_EQ(5, b.getPushes()[Button::D]);

  delete p;
}

TEST(TestObserver, PlayerNotifyUsE) {
  Player *p = new Player(Model::T, Variant::A);
  ButtonObserver b(p);
  for (int i = 0; i < 5; i++)
    p->pushButton(Button::E);
  EXPECT_EQ(5, b.getPushes()[Button::E]);

  delete p;
}
