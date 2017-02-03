#include "Medusa.hpp"

Medusa::Medusa()  //roll到12点攻击后，直接将对方石化，回合结束
{
  name = "Medusa";
  armor = 3;
  strength_points = 8;
}


int Medusa::attack()
{
  int dice_attack_roll = 2;
  int dice_attack_side = 6;
  
  int total_attack_points = total_points(dice_attack_roll, dice_attack_side);

  //Glare
  if (total_attack_points==12)
      total_attack_points=99999;

  return total_attack_points;
}


int Medusa::defense()
{
  int dice_defense_roll = 1;
  int dice_defense_side = 6;

  return total_points(dice_defense_roll, dice_defense_side);

}


void Medusa::revive()
{
    strength_points = 8;
}


