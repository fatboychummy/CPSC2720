/**
* @author Matthew Wilbern
* @date 2019-03
*/

#ifndef INCLUDE_PAUSECOMMAND_H_
#define INCLUDE_PAUSECOMMAND_H_

#include "Command.h"


class PauseCommand : public Command {
 public:
  PauseCommand(const Player *p);
  virtual ~PauseCommand();

  /**
  * @param p the player the command should effect.
  */
  void go();

 private:
  const Player *p;
};

#endif // INCLUDE_PAUSECOMMAND_H_
