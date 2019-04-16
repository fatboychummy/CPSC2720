/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <string>
#include "gtest/gtest.h"
#include "Inventory.h"
#include "Item.h"

TEST(TestInventory, maxItems) {
  Inventory i;
  int currentMaxItems = 5;
  EXPECT_EQ(i.getMaxItems(), currentMaxItems);
}

TEST(TestInventory, totalItems) {
  Inventory i;
  Item *ii = new Item("item1", "bla", true);
  Item *ii2 = new Item("item2", "bla", true);
  i.addItem(ii);
  i.addItem(ii2);

  EXPECT_EQ(i.getTotalItems(), 2);
}

TEST(TestInventory, addGetItemName) {
  Inventory i;
  std::string name = "test";
  Item *i2 = new Item(name, "bla", true);

  i.addItem(i2);

  EXPECT_EQ(i.getItem(name)->getName(), name);
}

TEST(TestInventory, addTooManyItems) {
  Inventory inv;
  Item *i = new Item("Item1", "bla", true);
  Item *i2 = new Item("Item2", "bla", true);
  Item *i3 = new Item("Item3", "bla", true);
  Item *i4 = new Item("Item4", "bla", true);
  Item *i5 = new Item("Item5", "bla", true);
  Item *i6 = new Item("Item6", "bla", true);
  inv.addItem(i);
  inv.addItem(i2);
  inv.addItem(i3);
  inv.addItem(i4);
  inv.addItem(i5);

  EXPECT_FALSE(inv.addItem(i6));

  delete i6;
}

TEST(TestInventory, getInventoryItemPtr) {
  Inventory inv;
  Item *i = new Item("Item1", "bla", true);
  inv.addItem(i);

  EXPECT_EQ(i, inv.getItems()->at(0));
}

TEST(TestInventory, removeItems) {
  Inventory inv;
  std::string name = "Item1";
  Item *i = new Item(name, "bla", true);
  inv.addItem(i);

  EXPECT_TRUE(inv.removeItem(name));
  delete i;
}
