/**
* @author Matthew Wilbern
* @date 2019-03
*/

#ifndef INCLUDE_MODECOMMAND_H_
#define INCLUDE_MODECOMMAND_H_

#include "Command.h"


class ModeCommand : public Command {
 public:
  ModeCommand(const Player *p);
  virtual ~ModeCommand();

  /**
  * @param p the player the command should effect.
  */
  void go();

 private:
  const Player *p;
};

#endif // INCLUDE_MODECOMMAND_H_
