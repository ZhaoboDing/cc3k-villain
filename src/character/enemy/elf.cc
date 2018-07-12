#include "elf.h"

elf::elf(): enemy{140, 30, 10, "elf", 'E'} {}

int elf::attack(character &defender) {
  int damage = 0;

  if (rand() % 2)
    damage += defender.defend(*this);

  if (defender.getRace() != "drow" && rand() % 2)
    damage += defender.defend(*this);

  return damage;
}