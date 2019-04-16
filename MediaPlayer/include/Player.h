/**
* @author Matthew Wilbern
* @date 2019-03
*/

#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <vector>
#include <map>
#include "PlayerSpec.h"
//#include "Command.h"
#include "Observer.h"

class Command;

enum class Button {
  A,
  B,
  C,
  D,
  E
};

class Player {
 public:
  /**
  * @param model the model the player should be
  * @param variant the variant the player should be
  */
  Player(Model model, Variant variant);
  virtual ~Player();

  /**
  * @return the player's specs
  */
  PlayerSpec* getSpec() const;

  /**
  * @param button the button to press
  */
  void pushButton(Button button);

  /**
  * @param obs the observer to be attached
  */
  void addObserver(Observer *obs);

  /**
  * searches the observer list for a matching pointer,
  * and removes it if found.
  * @param obs the observer to be removed
  */
  void delObserver(Observer *obs);

 private:
  void notify(Button b);

  PlayerSpec *specs;
  std::map<Button, Command*> commandMap;
  std::vector<Observer *> observers;
};

#endif // INCLUDE_PLAYER_H_
