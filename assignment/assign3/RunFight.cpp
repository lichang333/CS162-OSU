#include "RunFight.hpp"
#include <iostream>

CombatRunner::CombatRunner(Creature *p1, Creature *p2, int num_sims)
{
    this->p1 = p1;
    this->p2 = p2;
    this->total_sims = num_sims;
    this->cur_sim = 1;
}

bool CombatRunner::run_simulation()
{

    while (true)
    {
        int p1_attack = p1->attack();
        int p2_defense = p2->defense();
            p2->damage_take(p1_attack, p2_defense);
        if (p2->dead())
        {
            p1->revive();
            p2->revive();
            return p1_win;
        }
        
        int p2_attack = p2->attack();
        int p1_defense = p1->defense();
 
            p1->damage_take(p2_attack, p1_defense);
        
        if (p1->dead())
        {
            p1->revive();
            p2->revive();
            return p2_win;
        }
    }
}


int CombatRunner::get_result()
{
    int p1_num_wins = 0;

    while (cur_sim <= total_sims)
    {
    
        if (run_simulation() == p1_win)
            ++p1_num_wins;

    
        ++cur_sim;
    }

    return p1_num_wins;
}
