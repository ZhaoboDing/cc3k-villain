#ifndef ITEM_H
#define ITEM_H

#include <string>

class character;

class item : public cell {
  std::string name;
  char display;
  character *guardian;
public:
  item(std::string name, char display, character *guardian = nullptr);

  char getDisplay() const;
  std::string getName() const;
  character *getGuardian() const;
};

#endif
