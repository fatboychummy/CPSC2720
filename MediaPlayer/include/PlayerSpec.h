/**
* @author Matthew Wilbern
* @date 2019-03
*/

#ifndef INCLUDE_PLAYERSPEC_H_
#define INCLUDE_PLAYERSPEC_H_

#include <vector>

enum class Model {
  T,
  B,
  M
};

enum class Variant {
  A,
  R,
  D
};

enum class Mode {
  RADIO,
  MP3,
  VIDEO
};

class PlayerSpec {
 public:
  /**
  * @param model the model of the player
  * @param variant the variant of the player
  */
  PlayerSpec(Model model, Variant variant);
  virtual ~PlayerSpec();

  /**
  * @return the model of the player
  */
  Model getModel() const;

  /**
  * @return the variant of the player
  */
  Variant getVariant() const;

  /**
  * @return the current mode the player is in
  */
  Mode getMode() const;

  /**
  * @return a vector of possible modes for this type of player
  */
  std::vector<Mode> getModes() const;


  /**
  * switches to the next available mode
  */
  void swapMode();

 private:
  Model model;
  Variant variant;
  Mode mode;
  int modeNumber;
  std::vector<Mode> modes;
};

#endif // INCLUDE_PLAYERSPEC_H_
