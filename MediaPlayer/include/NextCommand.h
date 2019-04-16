/**
* @author Matthew Wilbern
* @date 2019-03
*/

#ifndef INCLUDE_NEXTCOMMAND_H_
#define INCLUDE_NEXTCOMMAND_H_

#include "Command.h"


class NextCommand : public Command {
 public:
  NextCommand(const Player *p);
  virtual ~NextCommand();

  /**
  * @param p the player the command should effect.
  */
  void go();

 private:
  const Player *p;
};

#endif // INCLUDE_NEXTCOMMAND_H_
