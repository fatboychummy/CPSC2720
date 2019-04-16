/**
* @author Matthew Wilbern
* @date 2019-03
*/

#ifndef INCLUDE_PLAYCOMMAND_H_
#define INCLUDE_PLAYCOMMAND_H_

#include "Command.h"


class PlayCommand : public Command {
 public:
  PlayCommand(const Player *p);
  virtual ~PlayCommand();

  /**
  * @param p the player the command should effect.
  */
  void go();

 private:
  const Player *p;
};

#endif // INCLUDE_PLAYCOMMAND_H_
