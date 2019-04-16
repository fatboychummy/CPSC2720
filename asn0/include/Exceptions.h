/**
* @author MB Wilbern <matthew.wilbern>, Dr. Anvik <john.anvik@uleth.ca>, LN Wilson <n.wilson@uleth.ca>
* @date 2019-01
*/

#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

//Exceptions related to Calculators.

class div_by_zero_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit div_by_zero_error(const char* errMessage) :
    // Throw an error, with the message "errMessage"
    std::runtime_error(errMessage) {
  }
};

#endif
