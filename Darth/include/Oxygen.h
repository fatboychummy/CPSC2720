/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_OXYGEN_H_
#define INCLUDE_OXYGEN_H_


class Oxygen {
 public:
  Oxygen();
  virtual ~Oxygen();

  /**
  * @param level the amount of oxygen to start with
  */
  void setOxygenLevel(int level);

  /**
  * @param level the max oxygen to be set
  */
  void setMaxLevel(int level);

  /**
  * @return the current maximum oxygen
  */
  int getMaxLevel();

  /**
  * @return the amount of oxygen remaining
  */
  int getOxygenLevel();

  /**
  * @return true if oxygen is equal to 0 (after decreasing), false otherwise.
  */
  bool decrease(int count);

  /**
  * @param level increase oxygen level by level (defaults to 1)
  */
  void increase(int level = 1);

 private:
  int oxygenLevel;
  int maxLevel;
};

#endif  // INCLUDE_OXYGEN_H_
