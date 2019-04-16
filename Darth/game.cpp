/***********************************
// Copyright 2019 Matthew Wilbern
// CPSC 2720
// @author Matthew Wilbern
// @date 2019-03
***********************************/

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <vector>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>

#include "Character.h"
#include "Door.h"
// #include "GameData.h"
#include "Inventory.h"
#include "Exceptions.h"
#include "Item.h"
#include "NPC.h"
#include "Oxygen.h"
#include "Player.h"
#include "Quest.h"
#include "QuestList.h"
#include "Room.h"
#include "Ship.h"
#include "Puzzle.h"
#include "KeyPadPuzzle.h"
#include "PasswordPuzzle.h"
#include "DeathButtonPuzzle.h"
#include "EscapeButtonPuzzle.h"
#include "ItemType.h"


// SKELETON FUNCTIONS
std::vector<Room*>* initializeRooms();

bool mainMenu();
bool goThroughDoor(Ship* s, std::vector<Room*>* allRooms, Room* current);
bool yayNay();
NPC* addNPCToRoom(Room* room, std::string name, std::string s1, std::string s2,
                  std::string s3 = "", Quest* quest = new Quest(),
Item* item = new Item("empty", "empty", false),
Item* takes = new Item("empty", "empty", false));
Door* addDoorToRoom(std::vector<Room*>* rooms, int l1, int l2,
                    bool lock = false, bool broke = false);
Item* addItemToRoom(Room* room, std::string name, std::string info,
                    bool reusable, ItemType type,
                    int count = 1);
Item* addKeyToRoom(Room* room, std::string name, std::string info,
                   bool reusable,
                   Door* cDoor, int count = 1);
Room* setupRoom(Room* room, std::string name,
                std::string searchInfo, std::string info = "");
std::string toHex(int number);
void questBook(Player* p);
void inv(Ship* s);
void search(Ship* s, bool *escapeFlag);
void printRoom(Room* room);
void clear();
void clear2();
void slowWrite(std::string stuff, unsigned int spd);
void runGame();


// CONSTANTS
const int TOTAL_ROOMS = 16;

// -------------------------------------------------MAIN
// -------------------------------------------------MAIN
// -------------------------------------------------MAIN
/*
*/
int main() {
  bool playAgain;
  char c = '\0';
  do {
    c = '\0';

    // Main menu returns false if we want to quit the game
    // true to play
    bool flag = mainMenu();

    if (!flag)  // If mainMenu returns false, quit game, else continue
      return 0;

    // Run the game
    runGame();

    // Ask the player if they want to play again.
    std::cout << "Would you like to play again?";
    playAgain = yayNay();

    // If playing again, clear the screen
    if (playAgain)
      clear();
  } while (playAgain);

  // Return ok
  return 0;
}


// --------------------------------------------GAME METHODS
// --------------------------------------------GAME METHODS
// --------------------------------------------GAME METHODS

/**
* runGame runs the main loop of the game.
*/
void runGame() {
  // Initialize the game flags to false
  bool oxyFlag = false;
  bool deadFlag = false;
  bool escapeFlag = false;
  char c = '\0';
  Ship s;
  {
    Quest* sq = new Quest();
    sq->setName("Escape the Ship");
    sq->setInfo("Through trial and error, you must"
                " find a way to escape your ship.");
    Player *p = new Player(sq);
    s.setPlayer(p);
  }
  Player *p = s.getPlayer();
  Oxygen *o = p->getOxygen();
  std::vector<Room*>* allRooms;
  clear();

  {
    char in = '\0';
    bool c = false;
    do {
      in = '\0';
      std::cout << "Enter a difficulty level (affects starting oxygen level)\n"
                << "(H) Hard - 5 oxygen\n(M) - Medium - 7 oxygen\n(E) Easy"
                " - 8 oxygen\n"
                << "(C) Crying Child - 20 oxygen\n>";
      std::cin >> in;
      in = tolower(in);
      switch (in) {
      case 'h':
        o->setMaxLevel(5);
        o->setOxygenLevel(5);
        c = true;
        break;
      case 'm':
        o->setMaxLevel(7);
        o->setOxygenLevel(7);
        c = true;
        break;
      case 'e':
        o->setMaxLevel(8);
        o->setOxygenLevel(8);
        c = true;
        break;
      case 'c':
        o->setMaxLevel(20);
        o->setOxygenLevel(20);
        c = true;
        break;
      default:
        std::cout << "Invalid.\n";
        sleep(1);
      }
      clear();
    } while (!c);
  }

  slowWrite("You are Obi Juan Kenobi, a space warrior that just woke"
            " up to a beeping alert, notifying you that there is a gas leak"
            " inside the ship, which could ultimately kill you. Due to the "
            "gas and the collision. you are currently dazed and confused "
            "without understanding what really happened, but your oxygen"
            " levels are extremely low. You find out your current location,"
            " but must find out how to exit this ship to survive. "
            "In your journey of survival, there will be items that you will"
            " require to exit the ship...but you may even find items that will "
            "extend your oxygen bar.\n\n"
            "You start with only so much oxygen, and it slowly ticks down with"
            " your every move.\n\n"
            "Enter anything to continue.\n>", 30000);

  // Output the intro

  std::string waste = "";
  do {
    if (waste != "")
      std::cout << "That doesn't look like 'anything' to me.\n>";
    std::cin >> waste;
  } while (waste != "anything");

  s.setRooms(initializeRooms());
  s.setCurrentRoom(s.getRooms()->at(0));
  // Initialize rooms, and the first room.

  // Get the std::vector of rooms
  allRooms = s.getRooms();

  {
    // Reset the IDs of the rooms, so if playing again it works.
    Room r;
    r.resetLastID();
  }

  // below: Set up all the rooms (painstakingly) one by one
  // ---------------------------------------------------------------------------
  // ---------------------------------------------------------------------------
  // ---------------------------------------------------------------------------

  {

    int c = 1;
    srand(time(NULL));
    int passcode = rand() % 9000 + 1000;
    std::string passstring = std::to_string(passcode);
    std::string sticky = "A small sticky note with the numbers '";
    sticky += passstring;
    sticky += "' written on it.";
    Room *r = setupRoom(allRooms->at(c-1), "Sleeping Quarters",
                        "This is your own room, you've lived here for a few years."
                        " However, you keep forgetting your passcode on your door, "
                        "so you keep a sticky note on your desk with the code.", "");
    addItemToRoom(r, "Sticky Note",
                  sticky,
                  false, ItemType::USELESS);

    Door *d = addDoorToRoom(allRooms, c, 2, true);
    addDoorToRoom(allRooms, c, 3, false);
    r->setPuzzle(new KeyPadPuzzle(p, passcode, d, StatusEffect::ACID, 1));
  }
  {
    Door *d3;
    srand(time(NULL)-128);
    int passpadcode = rand() % 9000 + 1000;
    {
      int c = 2;
      Room *r = setupRoom(allRooms->at(c-1), "Main Hallway",
                          "This is nothing but a long hallway. "
                          "However, you do notice a few things... "
                          "There is an oxygen mask on the floor, and "
                          "in front of the door leading to the "
                          "Medical Station, there lies a keypad.", "");
      addItemToRoom(r, "Oxygen Mask", "A mask which increases your oxygen"
                    " efficiency", false, ItemType::MAXOXYGENINCREASE);
      addDoorToRoom(allRooms, c, 1, false);
      addDoorToRoom(allRooms, c, 4, false);
      addDoorToRoom(allRooms, c, 5, false);
      Door *d = addDoorToRoom(allRooms, c, 6, true);
      Door *d2 = addDoorToRoom(allRooms, c, 7, true);
      d3 = addDoorToRoom(allRooms, c, 8, true);
      r->setPuzzle(new KeyPadPuzzle(p, passpadcode,
                                    d, StatusEffect::COLD, 2));
      Item *i5 = addKeyToRoom(allRooms->at(5), "Escape Pod Key",
                              "A key to the escape pod room. "
                              "This key can be used in the Main Hallway.", false, d2);
      allRooms->at(1)->addUsableItem(i5);
    }

    {
      int c = 3;
      Room *r = setupRoom(allRooms->at(c - 1), "Bathroom",
                          "A nice, clean bathroom. "
                          " Nothing much of use here.", "");
      addDoorToRoom(allRooms, c, 1, false);
    }

    {
      int c = 4;
      Room *r = setupRoom(allRooms->at(c - 1), "Bow Cafeteria",
                          "You search around the Cafeteria,"
                          " and see a man sitting in one "
                          "corner of the room.  "
                          "There is a jug of water on the floor.",
                          "");
      Quest *q = new Quest();
      q->setName("Find Towel for Billy");
      q->setInfo("Billy the janitor needs a towel to clean up his mess. "
                 "He has promised to give you an item \"worth your while\""
                 " in exchange.");
      Item *i = addItemToRoom(allRooms->at(2), "Towel", "A fluffy towel", false,
                              ItemType::USELESS);
      Item *i2 = new Item("Cockpit Key", "A key to the Cockpit. "
                          "This key can be used in the Main Hallway.", false);
      i2->setType(ItemType::KEY);
      i2->setUnlock(d3);
      allRooms->at(1)->addUsableItem(i2);

      addNPCToRoom(r, "Billy",
                   "Hi, I'm Billy.  I'm just a janitor, and with the whole ship "
                   "shaking like it has been, I spilled my mop bucket on the floor! "
                   "Could you find me a towel?  My towel is completely soaked already! "
                   "I've got something I can give you for your time."
                   "\nCome talk to me again when you have the towel!",
                   "Did you find the towel for me yet?",
                   "Thanks for getting me the towel!  Here, take this.",
                   q, i2, i);


      addDoorToRoom(allRooms, c, 2, false);
    }
    srand(time(NULL) + 32);
    int passcode = rand() % 9000 + 1000;
    {
      int c = 5;
      std::string reply = "";
      reply += "Congrats, your HEX code is ";
      reply += toHex(passcode);
      reply += ". Write it down before it's gone!";
      Room *r = setupRoom(allRooms->at(c - 1), "3D Printer Lab",
                          "There are a few 3D printers, one of "
                          "which is active.  You happen to notice"
                          " one of which has a question on it.", "");
      r->setPuzzle(new PasswordPuzzle(p, "penny",
                                      "What has a head, a tail, is brown"
                                      ", and has no legs?", reply,
                                      StatusEffect::POISON, 2));
      addDoorToRoom(allRooms, c, 2, false);
      addItemToRoom(r, "Oxygen Tank", "A tank of oxygen", false,
                    ItemType::OXYGENTANK);
    }

    {
      int c = 8;
      std::string answer = std::to_string(passcode);
      std::string reply = "Congrats. The code for the Medical Station is ";
      reply += std::to_string(passpadcode);
      reply += ".";
      Room *r = setupRoom(allRooms->at(c - 1), "Cockpit",
                          "There is a flight control computer."
                          " It seems to be locked with a passcode.", "");
      addDoorToRoom(allRooms, c, 2, false);
      r->setPuzzle(new PasswordPuzzle(p, answer,
                                      "Please enter the converted Decimal number.",
                                      reply,
                                      StatusEffect::FIRE, 3));
    }
  }
  {
    int c = 6;
    Room *r = setupRoom(allRooms->at(c - 1), "Medical Station",
                        "There are computers everywhere. "
                        "There is, however, "
                        "a blue button sitting on one of the walls."
                        "  You haven't "
                        "used it before, so you don't know what it does.", "");
    addItemToRoom(r, "Oxygen Mask",
                  "This oxygen mask will increase your maximum oxygen level.",
                  false, ItemType::MAXOXYGENINCREASE);

    addDoorToRoom(allRooms, c, 2, false);
    r->setPuzzle(new DeathButtonPuzzle(p));
  }

  {
    int c = 7;
    Room *r = setupRoom(allRooms->at(c - 1), "Escape Pod Room",
                        "There are many escape pods littered"
                        " about, and a large button "
                        "which is strikingly similar to "
                        "the one you saw in the Medical Station", "");
    addDoorToRoom(allRooms, c, 2, false);
    // addDoorToRoom(allRooms, c, 10, false);
    r->setPuzzle(new EscapeButtonPuzzle(&escapeFlag));
  }



  {
    int c = 9;
    Room *r = setupRoom(allRooms->at(c - 1), "Computer Room",
                        "There are computers everywhere.", "");
    addDoorToRoom(allRooms, c, 10, false);
  }

  {
    int c = 10;
    Room *r = setupRoom(allRooms->at(c - 1), "Lower Hallway",
                        "There are computers everywhere.", "");
    addDoorToRoom(allRooms, c, 9, false);
    addDoorToRoom(allRooms, c, 11, false);
    addDoorToRoom(allRooms, c, 13, false);
    addDoorToRoom(allRooms, c, 14, false);
    addDoorToRoom(allRooms, c, 15, false);
  }

  {
    int c = 11;
    Room *r = setupRoom(allRooms->at(c - 1), "Krypton Room",
                        "TODO: ADD DESCRIPTION", "");
    addDoorToRoom(allRooms, c, 10, false);
  }

  {
    int c = 12;
    Room *r = setupRoom(allRooms->at(c - 1), "",
                        "TODO: ADD DESCRIPTION", "");
    addDoorToRoom(allRooms, c, 10, false);
  }

  {
    int c = 13;
    Room *r = setupRoom(allRooms->at(c - 1), "Armory",
                        "TODO: ADD DESCRIPTION", "");
    addDoorToRoom(allRooms, c, 14, false);
  }

  {
    int c = 14;
    Room *r = setupRoom(allRooms->at(c - 1),
                        "Other Hallway",
                        "TODO: ADD DESCRIPTION", "");
    addDoorToRoom(allRooms, c, 10, false);
    addDoorToRoom(allRooms, c, 16, true);
    r->setPuzzle(new PasswordPuzzle(p,
                                    "TODO: ADD PASSWORD", "TODO: ADD OUTPUT1",
                                    "TODO: ADD OUTPUT2", StatusEffect::ACID, 10));
  }

  {
    int c = 15;
    Room *r = setupRoom(allRooms->at(c - 1), "Stern Cafeteria",
                        "TODO: ADD DESCRIPTION", "");
    addDoorToRoom(allRooms, c, 10, false);
  }

  {
    int c = 16;
    Room *r = setupRoom(allRooms->at(c - 1), "Loading Dock",
                        "TODO: ADD DESCRIPTION", "");
    addDoorToRoom(allRooms, c, 14, false);
    r->setPuzzle(new EscapeButtonPuzzle(&escapeFlag));
  }


  // Loop through the game
  do {
    clear();
    printRoom(s.getCurrentRoom());  // Output the room
    std::cout << "You have " << o->getOxygenLevel() << "/"
              << o->getMaxLevel() << " oxygen remaining. ";
    if (o->getOxygenLevel() == 1)
      std::cout << "You are about to die. ";
    else if (o->getOxygenLevel() < 4)
      std::cout << "It's getting really hard to breath. ";

    if (p->getStatus() == StatusEffect::COLD)
      std::cout << "You are COLD (1 extra oxygen / turn)";
    else if (p->getStatus() == StatusEffect::FIRE)
      std::cout << "You are ON FIRE (2 extra oxygen / turn)";
    else if (p->getStatus() == StatusEffect::POISON)
      std::cout << "You are POISONED (4 extra oxygen / turn)";
    else if (p->getStatus() == StatusEffect::ACID)
      std::cout << "You are COVERED IN ACID (6 extra oxygen / turn)";
    else if (p->getStatus() == StatusEffect::SEALING)
      std::cout << "Your oxygen tank is self-sealing ("
                << p->getStatusTime() / 2 + 1 <<
                " extra oxygen / turn)";

    std::cout << "\n>";
    // Tell the player they need to get a move on to some oxygen tanks
    std::cin >> c;
    // Wait for inputs.
    bool useOxygenFlag = false;
    bool quit;
    switch (tolower(c)) {
    case 's':
      search(&s, &escapeFlag);
      break;
    case 'd':
      if (goThroughDoor(&s, allRooms, s.getCurrentRoom()))
        useOxygenFlag = true;
      break;
    case 'b':
      questBook(p);
      break;
    case 'i':
      inv(&s);
      break;
    case 'q':
      std::cout << "Are you sure?";
      quit = yayNay();
      if (quit) {
        std::cout << "Goodbye, friend.\n";
        return;
      }
      break;
    default:
      std::cout << "Invalid command.\n";
      sleep(3);
    }

    if (useOxygenFlag) {
      oxyFlag = p->tick();
    }
    // If the player did a move which requires a decrease in oxygen
    // decrease the oxygen.
    deadFlag = !p->getAlive();
  } while (!oxyFlag && !deadFlag && !escapeFlag);
  // do x while player:
  // is not at 0 oxygen
  // is not dead
  // has not escaped
  clear2();

  if (oxyFlag)  // if out of oxygen...
    slowWrite("You ran out of oxygen and suffocated.\n\n", 30000);
  else if (deadFlag)  // if the player died...
    slowWrite("You scream in pain as your body is torn apart.\n\n", 30000);
  else if (escapeFlag)  // if the player escaped...
    slowWrite("Congrats on the escape!\n\n", 100000);
}

bool yayNay() {
  char c = '\0';
  do {
    if (c != '\0')
      std::cout << "Invalid input (Y/N)";
    std::cout << "\n>";
    std::cin >> c;
    c = tolower(c);
  } while (c != 'y' && c != 'n');

  return c == 'y';
}

/**
* mainMenu runs the main menu loop for the game
* @return if the game should quit or not.
*/
bool mainMenu() {
  /*
    Welcome to GAME_NAME!


    (N) New game
    (L) Load game
    (Q) Quit game
  */

  char c;
  // while the input is invalid, read until an N, L, or Q are read.
  do {
    std::cout << "Welcome to " << "Darth Shuttle" << "!\n\n\n"
              << "(N) New game\n(L) Load game\n(Q) Quit game";
    std::cout << "\n>";
    std::cin >> c;
    switch (tolower(c)) {
    case 'n':
      return true;
    case 'l':  // return false because "we have not implemented yet"
      std::cout << "Sorry, this feature does not work yet.\n";
      sleep(3);
      return false;
    case 'q':  // return false to "quit game"
      return false;
    default:
      std::cout << "Invalid command.\n";
      sleep(3);
      clear();
    }
  } while (true);
}

/**
* display the questBook
* @param p the player
*/
void questBook(Player *p) {
  QuestList *q = p->getQuests();
  std::vector<Quest*>* quests = q->getQuests();
  int inp = 0;
  do {
    inp = 0;
    // reset inp/low
    clear();
    std::cout << "(-1) Exit\n";
    for (int i = 0; i < quests->size(); i++) {
      // for each quest in quests...
      std::cout << "(" << i << ") " << quests->at(i)->getName() << ", ";
      if (quests->at(i)->isCompleted())
        std::cout << "Complete";
      else
        std::cout << "Incomplete";
      // questName: [Complete/Incomplete]
      std::cout << std::endl;
    }

    std::cout << std::endl << std::endl
              << "Type a quest index number to get more information about it.\n>";

    // get player input
    std::cin >> inp;
    if (inp >= -1 && inp < quests->size()) {
      clear();
      std::cout << quests->at(inp)->getName() << ": " << quests->at(
                  inp)->getInfo() << std::endl << std::endl;
      std::cout << "Type anything to continue.\n";
      std::string waste = "";
      do {
        if (waste != "")
          std::cout << "That doesn't look like 'anything' to me.\n";
        std::cin >> waste;
      } while (waste != "anything");

    } else if (inp != -1) {
      std::cout << "That quest doesn't exist.\n";
      sleep(3);
    }



    // if low != exit command, loop.
  } while (inp != -1);
}

/**
* display the inventory
* @param p the player
* @param currentRoom the current room the player is in, in case they want to drop an item
*/
void inv(Ship *s) {
  Room *r = s->getCurrentRoom();
  Player *p = s->getPlayer();
  Inventory *i = p->getInventory();
  std::vector<Item*>* inv = i->getItems();
  int inp = 0;

  do {
    clear();
    std::cout << "You are holding "
              << inv->size() << " of " << i->getMaxItems()
              << " items.\n\n";

    for (int i = 0; i < inv->size(); i++) {
      std::cout << "(" << i << ") " << inv->at(i)->getName() << std::endl;
    }

    std::cout << "(-1) Exit" << "\n\nEnter an item index to select it.\n>";

    std::cin >> inp;

    if (inp >= -1 && inp < inv->size()) {
      char inps = '\0';
      do {
        clear();
        std::cout << "Item: " << inv->at(inp)->getName()
                  << std::endl << std::endl
                  << "Description: "
                  << inv->at(inp)->getInfo() << std::endl << std::endl;
        if (r->checkUsableItems(inv->at(inp)->getName())
            || inv->at(inp)->getType() == ItemType::MAXOXYGENINCREASE
            || inv->at(inp)->getType() == ItemType::OXYGENTANK)
          std::cout << "(U) Use item\n";

        std::cout << "(D) Drop\n(B) Back\n>";
        std::cin >> inps;
        inps = tolower(inps);
        if (inps == 'u') {
          ItemType tp = inv->at(inp)->getType();
          Oxygen *o2 = p->getOxygen();

          if (p->useItem(inv->at(inp), r)) {
            if (tp == ItemType::MAXOXYGENINCREASE) {
              o2->setMaxLevel(o2->getMaxLevel()*2);
              o2->increase(o2->getMaxLevel()/4);
            } else if (tp == ItemType::OXYGENTANK) {
              o2->increase(o2->getMaxLevel()/2);
            }
            return;
          }
        } else if (inps == 'd') {
          r->addItem(inv->at(inp));
          i->removeItem(inv->at(inp)->getName());
          return;
        }
      } while (inps != 'b');
    }
  } while (inp != -1);
}

/**
* @param s the ship
*/
void search(Ship *s, bool *escapeFlag) {
  Room *r = s->getCurrentRoom();
  std::vector<Item*>* items = r->getSearchItems();
  char c = '\0';
  do {
    c = '\0';
    clear();
    std::cout << "Searching "
              << r->getRoomName() << ":" << std::endl << std::endl
              << r->getSearchInfo() << "\n\n";

    // Searching roomName: \n\n searchInfo

    for (int i = 0; i < items->size(); i++)
      // for each item in items...
      std::cout << "(" << i << ") pick up " << items->at(i)->getName() << std::endl;
    // i: pick up itemName\n
    std::cout << "(S) Stop searching\n";
    if (r->hasNPC())
      std::cout << "(N) Talk to NPC\n";
    if (r->hasPuzzle())
      std::cout << "(P) " << r->getPuzzle()->getName();

    std::cout << ">";
    std::cin >> c;

    if (isdigit(c)) {
      // if c = [0-9]...
      int ci = c - '0';
      if (ci >= 0 && ci < items->size()) {
        // if ci == an item index...
        Inventory *i = s->getPlayer()->getInventory();
        // grab the player's inventory
        Item *it = items->at(ci);
        if (i->addItem(it))
          items->erase(items->begin() + ci);
        // add the item to the player's inventory. (if space allows)
      }
    } else {
      switch (tolower(c)) {
      case 's':
        // if the player presses s, return.
        return;
        break;
      case 'n':
        // if the player presses n, talk to npc (if npc is present)
        if (r->hasNPC()) {
          NPC *npc = r->getNPC();
          if (npc->isQuester()) {
            // if the npc is a quest giver...
            Quest *q = npc->getQuest();
            if (!npc->hasGivenQuest()) {
              std::cout << npc->getName() << ": ";
              slowWrite(npc->talkTo(), 80000);
              sleep(5);
              // if the npc hasn't given the quest yet...
              s->getPlayer()->getQuests()->addQuest(q);
              npc->setGQuest(true);
              // give the quest to the player.

            } else if (npc->hasGivenQuest() &&
                       !npc->hasGivenItem() &&
                       !q->isCompleted()) {
              // if the npc has given quest,
              // but not the item, but the quest is completed...
              Inventory *inv = s->getPlayer()->getInventory();
              if (inv->removeItem(npc->getTakenItem()->getName())) {
                Item *it = npc->getItem();
                std::cout << npc->getName()
                          << " gave you a(n) "
                          << it->getName() << std::endl;
                if (!inv->addItem(it))
                  s->getCurrentRoom()->addItem(it);
              }
              std::cout << npc->getName() << ": ";
              slowWrite(npc->talkTo(), 80000);
              sleep(5);
            } else {
              std::cout << npc->getName() << " has nothing to say.\n";
              sleep(2);
            }
          }
        }
        break;
      case 'p':
        // if the player presses p, attempt puzzle (if puzzle present)
        if (r->hasPuzzle()) {
          clear();
          try {
            bool passed = r->getPuzzle()->play();
            if (passed)
              r->rmPuzzle();
            // If the puzzle was completed, remove it from the room.
            if (!s->getPlayer()->getAlive())
              return;
            else if (*escapeFlag)
              return;
            // if the player is dead from the puzzle, return.
          } catch (puzzle_quit_error& e) {

          }
        }
        break;
      default:
        std::cout << "Invalid command.\n";
        sleep(3);
      }
    }
  } while (true);
}

// ----------------------------------Room helper functions

/**
* @return a std::vector of semi-initialized rooms
*/
std::vector<Room*>* initializeRooms() {
  std::vector<Room*>* rooms = new std::vector<Room*>;
  for (int i = 0; i < TOTAL_ROOMS; i++) {
    rooms->push_back(new Room());
    // for each room, initialize it.
  }
  return rooms;
}

/**
* Sets up a room with name, info, etc.
* @param room the room to set up
* @param name the name of the room
* @param sInfo the std::string to be displayed when searching the room
* @param info the room's info
*/
Room* setupRoom(Room* room, std::string name,
                std::string sInfo, std::string info) {
  room->setSearchInfo(sInfo);
  room->setRoomName(name);
  room->setRoomInfo(info);
  return room;
  // set the name/info of the room
}

/**
* Adds a single door to a room
* @param rooms a list of all of the rooms
* @param l1 the ID of the first room
* @param l2 the ID of the second room
* @param lock if the door is locked or not
*/
Door* addDoorToRoom(std::vector<Room*>* rooms, int l1, int l2, bool lock,
                    bool broke) {
  Room *room = rooms->at(l1-1);
  Door* door = new Door(l1, l2, lock);
  if (broke)
    door->destroy();
  // create a new door with the inputs
  room->addDoor(door);
  // add the door to the room
  return door;
}

/**
* Adds a single item to a room
* @param room the room to add to
* @param name the name of the item
* @param info the info of the item
* @param reusable if the item is deleted after being used
* @param type the type of item
* @param count how many of the item there is
*/
Item* addItemToRoom(Room* room, std::string name, std::string info,
                    bool reusable, ItemType type,
                    int count) {
  //
  Item* i = new Item(name, info, reusable, count);
  i->setType(type);
  room->addItem(i);
  return i;
}


/**
* Adds a key to a room
* @param room the room to add to
* @param name the name of the item
* @param info the info of the item
* @param reusable if the item is deleted after being used
* @param cDoor the door the key is linked with
* @param count how many of the item there is
*/
Item* addKeyToRoom(Room* room, std::string name, std::string info,
                   bool reusable,
                   Door* cDoor, int count) {
  //
  Item* i = new Item(name, info, reusable, count);
  i->setUnlock(cDoor);
  i->setType(ItemType::KEY);
  room->addItem(i);
  return i;
}

/**
* @param number the number we want converted
* @return the hex value, as a string.
*/
std::string toHex(int number) {
  std::string base = "0123456789ABCDEF";
  std::string hex = "";
  while (number != 0) {
    hex = base[number%16] + hex;
    number /= 16;
  }
  hex = "0x" + hex;
  return hex;
}


/**
* display the contents of a room
* @param room the room to display
*/
void printRoom(Room* room) {
  std::string name = room->getRoomName();
  std::string info = room->getRoomInfo();
  std::cout << "You are currently in the " << name << ".\n\n"
            << info << "\n\n"
            << "(S) Search the room\n(D) Use door\n(B)"
            << " Open Questbook\n(I) Open Inventory\n(Q) Quit game\n\n";
  /*
    You are currently in the NAME_OF_ROOM.

    info_std::string

    (S) Search the room
    (1, 2, ...) Use door 1, 2, ...
    (B) Open Questbook

    >
  */
}

// --------------------------------------------------------------------------------Doors

/**
* asks and moves the player through a door.
* @param s the ship
* @param allRooms a list of all the rooms, to check if the door leads to a valid room
* @param current the current room the player is in.
*/
bool goThroughDoor(Ship *s, std::vector<Room*>* allRooms, Room* current) {
  clear();
  std::vector<Door*>* doors = current->getDoors();
  int c = -100;

  do {
    bool hit = false;  // A flag to see if our room has been found.
    std::cout << "(-1) Exit this dialogue.  You will not lose Oxygen.\n";

    for (int i = 0; i < doors->size(); i++) {
      // for each door in doors...
      std::cout <<"(" << doors->at(i)->getRoomID2() << ") "
                << allRooms->at(doors->at(i)->getRoomID2()-1)->getRoomName() << " ";

      if (doors->at(i)->isLocked())
        std::cout << "(LOCKED)";
      else if (!doors->at(i)->canOpen())
        std::cout << "(BLOCKED)";
      std::cout << std::endl;
      // 13: roomName [(LOCKED)/(BLOCKED)]
    }

    std::cout << "Enter a valid room number.\n>";
    std::cin >> c;

    for (int i = 0; i < doors->size(); i++) {
      // for each door in doors...
      if (c == doors->at(i)->getRoomID2()) {
        // if the opposite room ID == c
        hit = true;
        if (s->moveThroughDoor(doors->at(i))) {
          // if we can go through the door...
          std::cout << "You move through the door.\n";
          sleep(1);
          return true;
        } else if (doors->at(i)->isLocked()) {
          // if the door is locked...
          std::cout << "The door is locked and won't budge.\n";
          sleep(3);
        } else {
          // if the door is destroyed...
          std::cout << "The door looks too damaged to open.\n";
          sleep(3);
        }
      }
    }

    // if c = exit...
    if (c == -1)
      return false;

    // if no room was hit...
    if (!hit) {
      std::cout << "That door does not exist.\n";
      sleep(3);
    }
    clear();
  } while (true);  // F O R E V E R
}

// ------------------------------------------NPC stuff

/**
* adds an NPC to the room
* @param room the room to be added to
* @param name the name of the NPC
* @param s1 the first speech of the NPC
* @param s2 the second speech of the NPC
* @param s3 the third speech of the NPC (QuestGiver)
* @param quest the quest to give to the player (QuestGiver)
* @param item the item to give to the player (QuestGiver)
*/
NPC* addNPCToRoom(Room* room, std::string name,
                  std::string s1, std::string s2, std::string s3,
                  Quest* quest, Item* item, Item* takes) {
  NPC *npc = new NPC(name, s1, s2, s3, quest, item, takes);
  room->setNPC(npc);

  return npc;
}

// --------------------------------------------------------------------------------etc

/**
* clears the screen by outputting a large amount of newlines.
*/
void clear() {
  std::cin.clear();
  std::cin.ignore(INT_MAX, '\n');

  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
            << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  // std::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endl
  // std::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endl
}

/**
* clears the screen by without worrying about clearing std::cin
*/
void clear2() {
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
            << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  // std::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endl
  // std::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endlstd::endl
}

void slowWrite(std::string stuff, unsigned int spd) {
  for (std::string::size_type i = 0; i < stuff.size(); ++i) {
    std::cout << stuff[i] << std::flush;
    usleep(spd);
  }
}






