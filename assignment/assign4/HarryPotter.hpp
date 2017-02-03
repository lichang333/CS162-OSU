#pragma once

#include "Creature.hpp"

class HarryPotter : public Creature
{
public:
  bool is_hogwards;
  HarryPotter();
  virtual int attack();
  virtual int defense();
  virtual void revive();
  virtual int take_damage(int attack, int defense);
};

