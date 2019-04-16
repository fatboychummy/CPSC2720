/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include <vector>
#include "gtest/gtest.h"
#include "PlayerSpec.h"

// ------------------- Constructor Tests
// Model Tests
TEST(TestPlayerSpec, ConstructMB) {
  PlayerSpec ps(Model::B, Variant::A);
  EXPECT_EQ(Model::B, ps.getModel());
}

TEST(TestPlayerSpec, ConstructMT) {
  PlayerSpec ps(Model::T, Variant::A);
  EXPECT_EQ(Model::T, ps.getModel());
}

TEST(TestPlayerSpec, ConstructMM) {
  PlayerSpec ps(Model::M, Variant::A);
  EXPECT_EQ(Model::M, ps.getModel());
}

// Variant Tests
TEST(TestPlayerSpec, ConstructVA) {
  PlayerSpec ps(Model::B, Variant::A);
  EXPECT_EQ(Variant::A, ps.getVariant());
}

TEST(TestPlayerSpec, ConstructVR) {
  PlayerSpec ps(Model::B, Variant::R);
  EXPECT_EQ(Variant::R, ps.getVariant());
}

TEST(TestPlayerSpec, ConstructVD) {
  PlayerSpec ps(Model::B, Variant::D);
  EXPECT_EQ(Variant::D, ps.getVariant());
}

// ------------------- Constructor Modes Testing

/*
* Modes are set as following:
* Variant A: {[1] = MP3, [2] = RADIO, [3] = VIDEO}
* Variant R: {[1] = RADIO}
* Variant D: {[1] = MP3, [2] = VIDEO}
*/

TEST(TestPlayerSpec, ConstructModesA) {
  PlayerSpec ps(Model::B, Variant::A);
  std::vector<Mode> modes = ps.getModes();
  bool flg = true;

  if (modes[0] != Mode::MP3)
    flg = false;
  if (modes[1] != Mode::RADIO)
    flg = false;
  if (modes[2] != Mode::VIDEO)
    flg = false;
  EXPECT_TRUE(flg);

  modes.clear();
}

TEST(TestPlayerSpec, ConstructModesR) {
  PlayerSpec ps(Model::B, Variant::R);
  std::vector<Mode> modes = ps.getModes();
  bool flg = true;

  if (modes[0] != Mode::RADIO)
    flg = false;
  EXPECT_TRUE(flg);

  modes.clear();
}

TEST(TestPlayerSpec, ConstructModesD) {
  PlayerSpec ps(Model::B, Variant::D);
  std::vector<Mode> modes = ps.getModes();
  bool flg = true;

  if (modes[0] != Mode::MP3)
    flg = false;
  if (modes[1] != Mode::VIDEO)
    flg = false;
  EXPECT_TRUE(flg);

  modes.clear();
}

// ------------------- Mode Testing

// Variant A
TEST(TestPlayerSpec, ModeInitialA) {
  PlayerSpec ps(Model::B, Variant::A);
  EXPECT_EQ(Mode::MP3, ps.getMode());
}

TEST(TestPlayerSpec, ModeSwap1A) {
  PlayerSpec ps(Model::B, Variant::A);
  ps.swapMode();
  EXPECT_EQ(Mode::RADIO, ps.getMode());
}

TEST(TestPlayerSpec, ModeSwap2A) {
  PlayerSpec ps(Model::B, Variant::A);
  ps.swapMode();
  ps.swapMode();
  EXPECT_EQ(Mode::VIDEO, ps.getMode());
}

TEST(TestPlayerSpec, ModeOverflowA) {
  PlayerSpec ps(Model::B, Variant::A);
  ps.swapMode();
  ps.swapMode();
  ps.swapMode();
  EXPECT_EQ(Mode::MP3, ps.getMode());
}

// Variant R
TEST(TestPlayerSpec, ModeInitialR) {
  PlayerSpec ps(Model::B, Variant::R);
  EXPECT_EQ(Mode::RADIO, ps.getMode());
}

TEST(TestPlayerSpec, ModeSwapD) {
  PlayerSpec ps(Model::B, Variant::R);
  ps.swapMode();
  EXPECT_EQ(Mode::RADIO, ps.getMode());
}

// Variant D

TEST(TestPlayerSpec, ModeInitialD) {
  PlayerSpec ps(Model::B, Variant::D);
  EXPECT_EQ(Mode::MP3, ps.getMode());
}

TEST(TestPlayerSpec, ModeSwap1D) {
  PlayerSpec ps(Model::B, Variant::D);
  ps.swapMode();
  EXPECT_EQ(Mode::VIDEO, ps.getMode());
}

TEST(TestPlayerSpec, ModeOverflowD) {
  PlayerSpec ps(Model::B, Variant::D);
  ps.swapMode();
  ps.swapMode();
  EXPECT_EQ(Mode::MP3, ps.getMode());
}


