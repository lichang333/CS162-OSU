#include <iostream>

#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Creature.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampires.hpp"
#include "RunFight.hpp"


int main()
{
    const int NUM_CREATURES = 5;

    // fright time for each match up
    const int NUM_SIMULATIONS = 10000;

    // p1 and p2 
    Creature *set1[NUM_CREATURES] = { new Barbarian(), new BlueMen(), new HarryPotter(), new Medusa(), new Vampires() };
    Creature *set2[NUM_CREATURES] = { new Barbarian(), new BlueMen(), new HarryPotter(), new Medusa(), new Vampires() };


    for (int i = 0; i < NUM_CREATURES; ++i)
    {
        for (int j = 0; j < NUM_CREATURES; ++j)
        {
            Creature *p1 = set1[j];
            Creature *p2 = set2[i];
            CombatRunner cr(p1, p2, NUM_SIMULATIONS);

            std::cout << "P1: " << p1->get_name() << "  |   P2: " << p2->get_name() << '\n';

            // count win times 
            int p1_wins = cr.get_result();

            double p1_win_ratio = static_cast<double>(p1_wins) / NUM_SIMULATIONS;

            std::cout << "P1 wins " << (p1_win_ratio * 100) << "% of the 10000 times fight.\n";
            std::cout << "Press a key to continue...\n";
            std::cin.get();
        }
    }
    
    // free memory
    for (int i = 0; i < NUM_CREATURES; ++i)
    {
        delete set1[i];
        set1[i] = 0;
        delete set2[i];
        set2[i] = 0;
    }

    return 0;
}