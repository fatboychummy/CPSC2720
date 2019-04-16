/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#ifndef INCLUDE_QUEST_H_
#define INCLUDE_QUEST_H_

#include <string>

class Quest {
 public:
  Quest();
  virtual ~Quest();

  /**
  * @param info the info of the quest
  */
  void setInfo(std::string info);

  /**
  * @param name the name of the quest
  */
  void setName(std::string name);

  /**
  * @return the name of the quest
  */
  std::string getName();

  /**
  * @return the info of the quest
  */
  std::string getInfo();

  /**
  * @return if the quest is completed or not
  */
  bool isCompleted();

  /**
  * sets the quest's completion status to true.
  * A quest can not become "incomplete" after being completed.
  */
  void completeQuest();

 private:
  bool completed = false;
  std::string name;
  std::string info;
};

#endif  // INCLUDE_QUEST_H_
