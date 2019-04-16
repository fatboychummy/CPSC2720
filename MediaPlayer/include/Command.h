/**
* @author Matthew Wilbern
* @date 2019-03
*/

#ifndef INCLUDE_COMMAND_H_
#define INCLUDE_COMMAND_H_

//class Player;
#include "Player.h"

class Command {
 public:
  Command();

  /**
  * This function will be "Filled" to contain the command.
  * @param p the player the command should effect.
  */
  virtual void go() = 0;

 private:
  const Player *p;
};

#endif  // INCLUDE_COMMAND_H_
