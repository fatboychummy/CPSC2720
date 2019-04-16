/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include <iostream>
#include "ModeCommand.h"

ModeCommand::ModeCommand(const Player *p) {
  this->p = p;
}

ModeCommand::~ModeCommand() {
}

void ModeCommand::go() {
  p->getSpec()->swapMode();
  std::cout << "Changing Mode...\n";
}
