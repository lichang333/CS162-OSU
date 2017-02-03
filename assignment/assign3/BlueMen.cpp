#include "BlueMen.hpp"

BlueMen::BlueMen()
{
  name = "Blue Men";
  armor = 3;
  strength_points = 12;
}




int BlueMen::attack()
{
    int dice_attack_roll = 2;
    int dice_attack_side = 10;
    int total_attack_points = total_points(dice_attack_roll, dice_attack_side);

    return total_attack_points;
}



int BlueMen::defense()
{ 
  int dice_defense_roll = 3;
  // Mob
  if (strength_points<=8) dice_defense_roll=2;
  if (strength_points<=4) dice_defense_roll=1;
  int dice_defense_side = 6;

  return total_points(dice_defense_roll, dice_defense_side);

}




void BlueMen::revive()
{
    strength_points = 12;
}
