#pragma once

#include "Creature.hpp"

class Barbarian : public Creature
{
public:
    Barbarian();
    virtual int attack();
    virtual int defense();
    virtual void revive();
};




