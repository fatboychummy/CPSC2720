/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include <map>
#include <string>
#include "ButtonObserver.h"
#include "Exceptions.h"

ButtonObserver::~ButtonObserver() {
  pushes.clear();
}

ButtonObserver::ButtonObserver(Player *subject) {
  subject->addObserver(this);
  pushes[Button::A] = 0;
  pushes[Button::B] = 0;
  pushes[Button::C] = 0;
  pushes[Button::D] = 0;
  pushes[Button::E] = 0;
}

void ButtonObserver::notify(NotificationType type, std::string notif) {
  if (type == NotificationType::BUTTON) {
    if (notif.length() != 1)
      throw invalid_observer_format_error
      ("Button Observations must be 1 length.");
    if (notif == "A") {
      pushes[Button::A] += 1;
    } else if (notif == "B") {
      pushes[Button::B] += 1;
    } else if (notif == "C") {
      pushes[Button::C] += 1;
    } else if (notif == "D") {
      pushes[Button::D] += 1;
    } else if (notif == "E") {
      pushes[Button::E] += 1;
    } else {
      throw invalid_observer_format_error
      ("Button Observer was passed a button which does not exist!");
    }
  }
}

std::map<Button, int> ButtonObserver::getPushes() {
  return pushes;
}
