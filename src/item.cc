#include "item.h"

item::item(std::string name, char display, character *guardian = nullptr):
  name{name}, display{display}, guardian{guardian} {}

void item::getDisplay() const {
  return display;
}

std::string item::getName() const {
  return name;
}

void setGuardian(character *guardian) {
  this->guardian = guardian;
}
