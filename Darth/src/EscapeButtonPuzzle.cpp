/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <unistd.h>
#include <string>
#include <iostream>
#include "EscapeButtonPuzzle.h"

EscapeButtonPuzzle::EscapeButtonPuzzle(bool *complete) {
  gameCompleter = complete;
}

EscapeButtonPuzzle::~EscapeButtonPuzzle() {
}

bool EscapeButtonPuzzle::play() {
  unsigned int spd = 30000;
  std::string sev = "Your seat lowers towards the floor\n";
  std::string fou = "Your heart begins pounding, a side-effect of the"
          " combination of loud noises and the rumbling of the pod.\n";
  std::string one = "You say a silent prayer.\n";


  slowWrite("As you push the button, an escape pod door opens on your left. "
    "You run in it and quickly shut the door behind yourself.\n\n"
    "You dance your fingers across a keyboard and begin the startup"
    " procedures.\n\n", spd);

  usleep(spd*21);
  std::cout << "A metallic voice rings out, \"ENGINES. RAMPING. UP.\"\n\n";

  sleep(2);
  slowWrite("Your fingers continue across the keyboard as you continue to"
            " start critical systems.\n\n", spd);

  usleep(spd*21);
  std::cout << "\"ENGINES ONLINE.\"\n";
  usleep(spd*21);
  std::cout << "\"OXYGEN PRODUCTION ONLINE.\"\n";
  usleep(spd*21);
  std::cout << "\"NAVIGATION SYSTEMS ONLINE.\"\n";
  sleep(1);

  slowWrite("You initialize the last system,"
            " and your hand hovers over the last "
            "button you need to press.  After a moment of hesitation, you slam"
            " your fist down.\n\n", spd);
            usleep(spd*21);
  std::cout << "\"LAUNCH SEQUENCE INITIATED.\"\n";
  usleep(spd*21);

  slowWrite("The pod starts shaking around you as the engines begin to get"
            " louder and louder.\n\n", spd);
            usleep(spd*21);
  std::cout << "\"DETACHING FROM SHIP.\"\n";
  usleep(spd*21);

  slowWrite("The pod lurches forwards.\n\n", spd);

  usleep(spd*21);
  std::cout << "\"LAUNCH SUCCESS. ENGINES AHEAD, FULL.\"\n";
  usleep(spd*21);

  slowWrite("You are pushed back into your seat "
            "as the pod begins accelerating\n\n", spd);
  usleep(spd*21);

  std::cout << "\"HYPERDRIVE CHARGING\"\n";
  usleep(spd*21);
  slowWrite("The pod slowly begins humming,"
            " louder and louder as the seconds tick by.\n\n", spd);
  sleep(4);

  std::cout << "\"READY TO ENGAGE HYPERDRIVE\"\n";
  usleep(spd*21);
  slowWrite("Immediately your fist slams down"
            " upon the button as it begins flashing to "
            "let you know the hyperdrive is ready.\n\n", spd);
  usleep(spd*21);

  for (int i = 10; i > 0; --i) {
    std::cout << "\"ENGAGING IN " << i << "\"\n";
    int wait = 1000000;
    switch (i) {
     case 7:
      slowWrite(sev, spd/3);
      wait -= sev.size() * spd/3;
      break;
     case 4:
      slowWrite(fou, spd/6);
      wait -= fou.size() * spd/6;
      break;
     case 2:
      slowWrite(one, spd/3);
      wait -= one.size() * spd/3;
      break;
    }
    usleep(wait);
  }

  slowWrite("You are squished into the back of"
            " your seat as everything outside of the windows"
            " slowly turns a blinding white.", spd*2);

  usleep(spd*42);
  *gameCompleter = true;
}


void EscapeButtonPuzzle::slowWrite(std::string stuff, unsigned int spd) {
  for (std::string::size_type i = 0; i < stuff.size(); ++i) {
    std::cout << stuff[i] << std::flush;
    usleep(spd);
  }
}

std::string EscapeButtonPuzzle::getName() {
  return "Press the Peculiar Button\n";
}
