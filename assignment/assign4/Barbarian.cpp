#include "Barbarian.hpp"

Barbarian::Barbarian()
{
  name = "Barbarian";
  strength_points = 12;
  armor = 0;
}

int Barbarian::attack()
{
    int dice_attack_roll = 2;
    int dice_attack_side = 6;

    int total_attack_points = total_points(dice_attack_roll, dice_attack_side);

    return total_attack_points;
}


int Barbarian::defense()
{
    int dice_defense_roll = 2;
    int dice_defense_side = 6;

    return total_points(dice_defense_roll, dice_defense_side);
}


void Barbarian::revive()
{
    strength_points = 12;
}
