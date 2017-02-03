#pragma once

#include "Creature.hpp"

class Medusa : public Creature
{
public:
  Medusa();
  virtual int attack(); 
  virtual int defense();
  virtual void revive();
};










