/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include <iostream>
#include "NextCommand.h"

NextCommand::NextCommand(const Player *p) {
  this->p = p;
}

NextCommand::~NextCommand() {
}

void NextCommand::go() {
  if (p->getSpec()->getMode() == Mode::MP3)
    std::cout << "Next Song\n";
  else if (p->getSpec()->getMode() == Mode::RADIO)
    std::cout << "Seeking Next Station\n";
  else if (p->getSpec()->getMode() == Mode::VIDEO)
    std::cout << "Next Video\n";
}
