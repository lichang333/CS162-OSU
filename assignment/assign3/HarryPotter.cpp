#include "HarryPotter.hpp"

HarryPotter::HarryPotter()
{
  name = "Harry Potter";
  armor = 0;
  strength_points = 10;
  is_hogwards=false;

}


int HarryPotter::attack()
{
    int dice_attack_roll = 2;
    int dice_attack_side = 6;

    int total_attack_points = total_points(dice_attack_roll, dice_attack_side);

    return total_attack_points;
}


int HarryPotter::defense()
{
    int dice_defense_roll = 2;
    int dice_defense_side = 6;

    return total_points(dice_defense_roll, dice_defense_side);
}


void HarryPotter::revive()
{
    strength_points = 10;
    is_hogwards=false;
}

int HarryPotter::take_damage(int attack, int defense)
{
    if (attack==99999) is_hogwards=true; //If opponent is Medusa, and she roll 12.  :(
    attack -= armor;
    int damage = attack - defense;

    if (damage > 0)
    {
        strength_points -= damage;
        if ((strength_points<=0)&&(is_hogwards==false))
        {
          //should hogwards
          strength_points=20;
          is_hogwards=true;
        }
        return damage;
    }

    return 0;
}
