#pragma once

#include "Creature.hpp"

class Vampires : public Creature
{
public:
	Vampires();
    virtual int attack();
    virtual int defense();
    virtual int damage_take(int attack, int defense);
    virtual void revive();
};





