#include "Creature.hpp"
#include <cstdlib>
#include <ctime>

Creature::Creature():win_points(0)
{
    srand(static_cast<unsigned int>(time(0)));

    rand();
}


int Creature::damage_take(int attack, int defense)
{
    attack -= armor;
    int damage = attack - defense;

    if (damage > 0)
    {
        strength_points -= damage;
        return damage;
    }

    return 0;
}

bool Creature::dead()
{
    return strength_points <= 0;
}

		
int Creature::total_points(int num_dice, int sides)
{
    int sum(0);
    for (int die = 0; die < num_dice; ++die)
        sum += rand() % sides + 1;

    return sum;
}



std::string Creature::get_name()
{
    return name;
}
