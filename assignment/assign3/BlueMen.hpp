#pragma once

#include "Creature.hpp"

class BlueMen : public Creature
{
public:
  BlueMen();
    virtual int attack();
    virtual int defense();
    virtual void revive();
};
