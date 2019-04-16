/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include <iostream>
#include "PauseCommand.h"

PauseCommand::PauseCommand(const Player *p) {
  this->p = p;
}

PauseCommand::~PauseCommand() {
  //dtor
}

void PauseCommand::go() {
  if (p->getSpec()->getMode() == Mode::MP3)
    std::cout << "Pausing Song\n";
  else if (p->getSpec()->getMode() == Mode::RADIO)
    std::cout << "Stopping Radio\n";
  else if (p->getSpec()->getMode() == Mode::VIDEO)
    std::cout << "Pausing Video\n";
}
