#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "cell.h"

class enemy;
class character;

class item : public cell {
protected:
  std::string name;
  enemy *guardian;
public:
  item(std::string name, char display, character *guardian = nullptr);

  char getDisplay() const;
  std::string getName() const;

  void setGuardian(enemy *guardian);
  virtual void use() = 0;
};

#endif
