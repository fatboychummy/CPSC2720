/**
* @author Matthew Wilbern
* @date 2019-03
*/

#ifndef INCLUDE_PLAYERFACTORY_H_
#define INCLUDE_PLAYERFACTORY_H_

#include <string>
#include "Player.h"

class PlayerFactory {
 public:
  PlayerFactory();
  virtual ~PlayerFactory();
  /**
  * @param modelType the model and variant of the player.
  * Example: MBVA is Model B, Variant A
  */
  Player getPlayer(std::string modelType);
};

#endif // INCLUDE_PLAYERFACTORY_H_
