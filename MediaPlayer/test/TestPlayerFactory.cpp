/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include "gtest/gtest.h"
#include "PlayerFactory.h"
#include "Player.h"
#include "Exceptions.h"



// MODEL T
TEST(TestPlayerFactory, MTVAModel) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MTVA");
  EXPECT_EQ(Model::T, p.getSpec()->getModel());
}

TEST(TestPlayerFactory, MTVAVariant) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MTVA");
  EXPECT_EQ(Variant::A, p.getSpec()->getVariant());
}


TEST(TestPlayerFactory, MTVRModel) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MTVR");
  EXPECT_EQ(Model::T, p.getSpec()->getModel());
}

TEST(TestPlayerFactory, MTVRVariant) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MTVR");
  EXPECT_EQ(Variant::R, p.getSpec()->getVariant());
}


TEST(TestPlayerFactory, MTVDModel) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MTVD");
  EXPECT_EQ(Model::T, p.getSpec()->getModel());
}

TEST(TestPlayerFactory, MTVDVariant) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MTVD");
  EXPECT_EQ(Variant::D, p.getSpec()->getVariant());
}

// MODEL B
TEST(TestPlayerFactory, MBVAModel) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MBVA");
  EXPECT_EQ(Model::B, p.getSpec()->getModel());
}

TEST(TestPlayerFactory, MBVAVariant) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MBVA");
  EXPECT_EQ(Variant::A, p.getSpec()->getVariant());
}


TEST(TestPlayerFactory, MBVRModel) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MBVR");
  EXPECT_EQ(Model::B, p.getSpec()->getModel());
}

TEST(TestPlayerFactory, MBVRVariant) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MBVR");
  EXPECT_EQ(Variant::R, p.getSpec()->getVariant());
}


TEST(TestPlayerFactory, MBVDModel) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MBVD");
  EXPECT_EQ(Model::B, p.getSpec()->getModel());
}

TEST(TestPlayerFactory, MBVDVariant) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MBVD");
  EXPECT_EQ(Variant::D, p.getSpec()->getVariant());
}

// MODEL M
TEST(TestPlayerFactory, MMVAModel) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MMVA");
  EXPECT_EQ(Model::M, p.getSpec()->getModel());
}

TEST(TestPlayerFactory, MMVAVariant) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MMVA");
  EXPECT_EQ(Variant::A, p.getSpec()->getVariant());
}


TEST(TestPlayerFactory, MMVRModel) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MMVR");
  EXPECT_EQ(Model::M, p.getSpec()->getModel());
}

TEST(TestPlayerFactory, MMVRVariant) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MMVR");
  EXPECT_EQ(Variant::R, p.getSpec()->getVariant());
}


TEST(TestPlayerFactory, MMVDModel) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MMVD");
  EXPECT_EQ(Model::M, p.getSpec()->getModel());
}

TEST(TestPlayerFactory, MMVDVariant) {
  PlayerFactory pf;
  Player p = pf.getPlayer("MMVD");
  EXPECT_EQ(Variant::D, p.getSpec()->getVariant());
}

// exceptions

TEST(TestPlayerFactory, InvalidFormatM) {
  PlayerFactory pf;
  EXPECT_THROW(pf.getPlayer("BTVA"), invalid_format_error);
}

TEST(TestPlayerFactory, InvalidFormatV) {
  PlayerFactory pf;
  EXPECT_THROW(pf.getPlayer("MTBA"), invalid_format_error);
}

TEST(TestPlayerFactory, InvalidFormat2) {
  PlayerFactory pf;
  EXPECT_THROW(pf.getPlayer("MZVA"), invalid_format_error);
}

TEST(TestPlayerFactory, InvalidFormat4) {
  PlayerFactory pf;
  EXPECT_THROW(pf.getPlayer("MTVZ"), invalid_format_error);
}

TEST(TestPlayerFactory, InvalidFormatLength) {
  PlayerFactory pf;
  EXPECT_THROW(pf.getPlayer("BTVAA"), invalid_format_error);
}
