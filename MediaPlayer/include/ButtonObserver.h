/**
* @author Matthew Wilbern
* @date 2019-03
*/

#ifndef INCLUDE_BUTTONOBSERVER_H_
#define INCLUDE_BUTTONOBSERVER_H_

#include <map>
#include <string>
#include "Observer.h"
#include "Player.h"

class ButtonObserver : public Observer {
 public:
  virtual ~ButtonObserver();

  /**
  * @param subject the player this observer should attach itself to
  */
  ButtonObserver(Player *subject);

  /**
  * @param type the type of notification
  * @param notif the notification string to be parsed
  */
  void notify(NotificationType type, std::string notif);

  /**
  * @return a map for the button presses
  */
  std::map<Button, int> getPushes();

 private:
  std::map<Button, int> pushes;
};

#endif // INCLUDE_BUTTONOBSERVER_H_
