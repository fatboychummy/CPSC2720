/**
* @author Matthew Wilbern
* @date 2019-03
*/

#ifndef INCLUDE_OBSERVER_H_
#define INCLUDE_OBSERVER_H_

#include <string>

enum class NotificationType {
  BUTTON,
  OTHER
};

class Observer {
 public:
  Observer();

  /**
  * @param type the type of notification
  * @param notif the string notification to be parsed by the observer
  */
  virtual void notify(NotificationType type, std::string notif) = 0;
};

#endif // INCLUDE_OBSERVER_H_
