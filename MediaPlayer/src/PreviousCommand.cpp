/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include <iostream>
#include "PreviousCommand.h"

PreviousCommand::PreviousCommand(const Player *p) {
  this->p = p;
}

PreviousCommand::~PreviousCommand() {
  //dtor
}

void PreviousCommand::go() {
  if (p->getSpec()->getMode() == Mode::MP3)
    std::cout << "Previous Song\n";
  else if (p->getSpec()->getMode() == Mode::RADIO)
    std::cout << "Seeking Previous Station\n";
  else if (p->getSpec()->getMode() == Mode::VIDEO)
    std::cout << "Previous Video\n";
}
