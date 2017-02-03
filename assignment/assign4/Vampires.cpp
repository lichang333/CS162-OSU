#include "Vampires.hpp"

Vampires::Vampires()
{
    name = "Vampires";
    armor = 1;
    strength_points = 18;
}

int Vampires::attack()
{
  int dice_attack_roll = 1;
  int dice_attack_side = 12;
  int total_attack_points = total_points(dice_attack_roll, dice_attack_side);

  return total_attack_points;
}



int Vampires::defense()
{
  int dice_defense_roll = 1;
  int dice_defense_side = 6;

    return total_points(dice_defense_roll, dice_defense_side);
}



int Vampires::damage_take(int attack, int defense)
{
    // Charm
    if (rand() % 2)
        return 0;

    return Creature::damage_take(attack, defense);
}




void Vampires::revive()
{
    strength_points = 18;
}

