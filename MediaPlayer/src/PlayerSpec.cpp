/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include <vector>
#include "PlayerSpec.h"

PlayerSpec::PlayerSpec(Model model, Variant variant) {
  if (variant == Variant::A) {
    modes.push_back(Mode::MP3);
    modes.push_back(Mode::RADIO);
    modes.push_back(Mode::VIDEO);
  } else if (variant == Variant::R) {
    modes.push_back(Mode::RADIO);
  } else if (variant == Variant::D) {
    modes.push_back(Mode::MP3);
    modes.push_back(Mode::VIDEO);
  }
  this->model = model;
  this->variant = variant;
  mode = modes[0];
  modeNumber = 0;
}

PlayerSpec::~PlayerSpec() {
  modes.clear();
}

Model PlayerSpec::getModel() const {
  return model;
}

Variant PlayerSpec::getVariant() const {
  return variant;
}

Mode PlayerSpec::getMode() const {
  return mode;
}

std::vector<Mode> PlayerSpec::getModes() const {
  return modes;
}

void PlayerSpec::swapMode() {
  modeNumber = (modeNumber+1)%modes.size();
  mode = modes[modeNumber];
}
