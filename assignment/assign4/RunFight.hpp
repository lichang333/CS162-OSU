#pragma once

#include <vector>

#include "Queue.hpp"
#include "Stack.hpp"
#include "Creature.hpp"


class RunFight
{

private:
    static const bool p1_win = true;
    static const bool p2_win = false;

    // players
    Creature *p1;
    Creature *p2;

    Queue *side1;
    Queue *side2;

    Stack *losers;
    Stack *losers1;
    Stack *losers2;

    int side1pts;
    int side2pts;


    std::vector<int> defeat_sides;

    int total_sims;

    // current simulation number
    int cur_sim;

public:
    RunFight(Queue *p1, Queue *p2, int num_sims);
    ~RunFight();

    bool run_simulation();
    int run_tournament();

    int get_result();
    int play_match(Creature* p1, Creature* p2);
    void print_outcome();
    void print_top_three();
    int get_win_points() ;

};

