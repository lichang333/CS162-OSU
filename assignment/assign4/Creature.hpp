#pragma once

#include <cstdlib>
#include <string>

class Creature
{
protected:
    int armor;
    int strength_points;
    int win_points;         // keep track of success in tournament

public:
    std::string name;
    Creature();
    virtual int attack() = 0;
    virtual int defense() = 0;
    virtual int damage_take(int attack, int defense);
    virtual void revive() = 0;
    bool dead();

    // helper for the attack() and defend() functions
    int total_points(int num_dice, int sides);
    std::string get_name();
    int get_win_points() { return win_points; }
};

