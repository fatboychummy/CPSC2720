/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include <iostream>
#include "PlayCommand.h"

PlayCommand::PlayCommand(const Player *p) {
  this->p = p;
}

PlayCommand::~PlayCommand() {
  //dtor
}

void PlayCommand::go() {
  if (p->getSpec()->getMode() == Mode::MP3)
    std::cout << "Playing Song\n";
  else if (p->getSpec()->getMode() == Mode::RADIO)
    std::cout << "Playing Radio\n";
  else if (p->getSpec()->getMode() == Mode::VIDEO)
    std::cout << "Playing Video\n";
}

