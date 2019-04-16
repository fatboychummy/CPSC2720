/**
* @author Matthew Wilbern
* @date 2019-03
*/

#ifndef INCLUDE_PREVIOUSCOMMAND_H_
#define INCLUDE_PREVIOUSCOMMAND_H_

#include "Command.h"


class PreviousCommand : public Command {
 public:
  PreviousCommand(const Player *p);
  virtual ~PreviousCommand();

  /**
  * @param p the player the command should effect.
  */
  void go();

 private:
  const Player *p;
};

#endif // INCLUDE_PREVIOUSCOMMAND_H_
