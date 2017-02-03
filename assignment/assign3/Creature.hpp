#pragma once

#include <cstdlib>
#include <string>

class Creature
{
protected:
    int armor;
    int strength_points;
    std::string name;

public:
    Creature();
    virtual int attack() = 0;
    virtual int defense() = 0;
    virtual int damage_take(int attack, int defense);
    virtual void revive() = 0;
    bool dead();

    // helper for the attack() and defend() functions
    int total_points(int num_dice, int sides);
    std::string get_name();
};

