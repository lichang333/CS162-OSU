#pragma once

#include "Creature.hpp"
// #include "Barbarian.hpp"

class CombatRunner
{
private:
    static const bool p1_win = true;
    static const bool p2_win = false;

    // players
    Creature *p1;
    Creature *p2;

    // total number of simulations
    int total_sims;

    // current simulation number
    int cur_sim;

public:
    CombatRunner(Creature *p1, Creature *p2, int num_sims);
    bool run_simulation();
    int get_result();

};

