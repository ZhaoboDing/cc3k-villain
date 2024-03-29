#include "floor.h"
#include "readMap.h"
#include "character/allCharacters.h"
#include "item/allItems.h"
#include "window.h"
#include <string>
#include <iostream>
#include <cstdlib>

inline bool gameOver() {
  std::cout << "You lose" << std::endl;
  std::cout << "Enter 'r' to RESTART the game or enter 'q' to EXIT the game: " << std::endl;
  std::string command;
  while(std::getline(std::cin, command)){
    if(command == "q"){
      return false;
    }
    if(command == "r") {
      return true;
    }
  }
}

inline bool game(bool isMapGiven, std::string mapName) {
  Xwindow *win = new Xwindow(1000, 600);
  std::cout << "Hello, welcome to CC3K...(we will add some words here later)" << std::endl;
  std::cout << "First, choose your race among Drow, Goblin, Shade, Troll and Vampire" << std::endl;
  std::string race;
  player *PC;
  while (std::getline(std::cin, race))
    if (race == "Drow") {
      PC = new drow;
      break;
    }
    else if (race == "Goblin") {
      PC = new goblin;
      break;
    }
    else if (race == "Shade") {
      PC = new shade;
      break;
    }
    else if (race == "Troll") {
      PC = new troll;
      break;
    }
    else if (race == "Vampire") {
      PC = new vampire;
      break;
    }
    else
      std::cout << "Invalid input, please choose again." << std::endl;

  std::string command;
  for (int curFloor = 1; curFloor <= 5; curFloor++) {
    PC->reset();
    floor gameFloor(readMap(mapName), PC, curFloor,isMapGiven);
    gameFloor.paint("New floor!", win);
    while (std::getline(std::cin, command)) {
      if (command == "q") {
        delete PC;
        delete win;
        return false;
      }
      if (command == "r") {
        delete PC;
        delete win;
        return true;
      }
      std::string action = gameFloor.PCTurn(command);
      if (action == "?") {
        std::cout << "Invalid input" << std::endl;
        continue;
      }
      if (PC->getHp() == 0) {
        gameFloor.paint(action, win);
        delete PC;
        delete win;
        return gameOver();
      }
      if (gameFloor.passedFloor()) break;
      action += "\n" + gameFloor.enemyTurn();
      if (PC->getHp() == 0) {
        gameFloor.paint(action);
        delete PC;
        delete win;
        return gameOver();
      }
      gameFloor.paint(action, win);
    }
  }

  std::cout << "You win! Score :" << PC->getGold() << std::endl;
  delete PC;
  delete win;
  return false;
}

int main(int argc, char *argv[]) {
  //read in given digital map
  std::string fileName = "";
  if(argc > 1){
    fileName = argv[1];
    game(true,fileName);
  }
  else{
    srand((unsigned)time(NULL));
    while (game(false,"map.txt"))
      std::cout << "Game restart!" << std::endl;
    return 0;
  }

}
