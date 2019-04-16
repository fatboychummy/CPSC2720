/**
* @author Matthew Wilbern
* @date 2019-03
*/


#include "Player.h"
#include "PlayCommand.h"
#include "PreviousCommand.h"
#include "PauseCommand.h"
#include "ModeCommand.h"
#include "NextCommand.h"

Player::~Player() {
  delete specs;
  delete commandMap[Button::A];
  delete commandMap[Button::B];
  delete commandMap[Button::C];
  delete commandMap[Button::D];
  delete commandMap[Button::E];
}

Player::Player(Model model, Variant variant) {
  specs = new PlayerSpec(model, variant);
  // Command Map Below Here
  PlayCommand *PL = new PlayCommand(this);
  NextCommand *NC = new NextCommand(this);
  PauseCommand *PA = new PauseCommand(this);
  ModeCommand *MC = new ModeCommand(this);
  PreviousCommand *PR = new PreviousCommand(this);

  if (model == Model::T) {
    commandMap[Button::A] = PR;
    commandMap[Button::B] = NC;
    commandMap[Button::C] = PA;
    commandMap[Button::D] = MC;
    commandMap[Button::E] = PL;
  } else if (model == Model::B) {
    commandMap[Button::A] = PL;
    commandMap[Button::B] = PR;
    commandMap[Button::C] = NC;
    commandMap[Button::D] = PA;
    commandMap[Button::E] = MC;
  } else if (model == Model::M) {
    commandMap[Button::A] = MC;
    commandMap[Button::B] = PR;
    commandMap[Button::C] = NC;
    commandMap[Button::D] = PL;
    commandMap[Button::E] = PA;
  }
}

PlayerSpec* Player::getSpec() const {
  return specs;
}

void Player::pushButton(Button button) {
  notify(button);
  commandMap[button]->go();
}

void Player::addObserver(Observer *obs) {
  observers.push_back(obs);
}

void Player::delObserver(Observer *obs) {
  for (int i = 0; i < observers.size(); i++) {
    if (obs == observers[i])
      observers.erase(observers.begin() + i);
  }
}

void Player::notify(Button b) {
  for (int i = 0; i < observers.size(); i++) {
    if (b == Button::A) {
      observers[i]->notify(NotificationType::BUTTON, "A");
    } else if (b == Button::B) {
      observers[i]->notify(NotificationType::BUTTON, "B");
    } else if (b == Button::C) {
      observers[i]->notify(NotificationType::BUTTON, "C");
    } else if (b == Button::D) {
      observers[i]->notify(NotificationType::BUTTON, "D");
    } else if (b == Button::E) {
      observers[i]->notify(NotificationType::BUTTON, "E");
    }
  }
}
