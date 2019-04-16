/**
* @author Matthew Wilbern
* @date 2019-03
*/

#include <string>
#include "PlayerFactory.h"
#include "Exceptions.h"

PlayerFactory::PlayerFactory() {
}

PlayerFactory::~PlayerFactory() {
}

Player PlayerFactory::getPlayer(std::string modelType) {
  if (modelType.length() != 4)
    throw invalid_format_error("PlayerFactory expects all ModelStrings"
                               " to be 4 characters long!");

  // below: if not MXVY, error. (X = {T, B, M}, Y = {A, R, D})
  if (modelType.at(0) != 'M'
      || modelType.at(2) != 'V'
      || modelType.at(1) != 'T' && modelType.at(1) != 'B'
      && modelType.at(1) != 'M'
      || modelType.at(3) != 'A' && modelType.at(3) != 'R'
      && modelType.at(3) != 'D')
    throw invalid_format_error("PlayerFactory expects the string to be"
                               " formatted like so: \"M<T,B,M>V<A,R,D>\"");
  Model m;
  Variant v;
  if (modelType.at(1) == 'T')
    m = Model::T;
  else if (modelType.at(1) == 'B')
    m = Model::B;
  else if (modelType.at(1) == 'M')
    m = Model::M;

  if (modelType.at(3) == 'A')
    v = Variant::A;
  else if (modelType.at(3) == 'R')
    v = Variant::R;
  else if (modelType.at(3) == 'D')
    v = Variant::D;

  Player p(m, v);

  return p;
}
