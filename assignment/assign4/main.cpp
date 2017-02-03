#include <iostream>
#include <cstdlib>
#include <vector>

#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Creature.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampires.hpp"
#include "RunFight.hpp"

#include "Queue.hpp"
#include "itools.hpp"


Creature* pickup_creature(char c);
void display_creature();

int main()
{
    const int MIN_LINEUP = 2;
    const int MAX_LINEUP = 20;

	Queue player1;
    Queue player2;

	int creature_lineup;

	std::cout<<"How many Creture have in this battle? \n";

    creature_lineup =itools::is_valid_int_range(MIN_LINEUP, MAX_LINEUP);
    char c = '\0';

    std::vector<Creature*> vector1;
    std::vector<Creature*> vector2;


	std::cout << "Player 1: Choose your Character lineup: \n";
    display_creature();
    for (int i = 0; i < creature_lineup; ++i)
    {
        c = '\0';

        while (!(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e'))
           c = std::cin.get();

        vector1.push_back(pickup_creature(c));
        player1.add(vector1[i]);
    }


	std::cout<<"Player 2: Choose your Character lineup: \n";
	display_creature();
	for (int i = 0; i < creature_lineup; ++i)
    {
        c = '\0';
        while (!(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e'))
           c = std::cin.get();

        vector2.push_back(pickup_creature(c));
        player2.add(vector2[i]);
    }


    RunFight cr(&player1, &player2,1);
    cr.print_outcome();

        for (int i = 0; i < creature_lineup; ++i)
    {
        delete vector1[i];
        delete vector2[i];
    }

    return 0;


}



Creature* pickup_creature(char c)
{
	switch (c)
    {
		case 'a': return new Barbarian;
        case 'b': return new BlueMen;
        case 'c': return new HarryPotter;
        case 'd': return new Medusa;
        case 'e': return new Vampires;
    }
    return NULL;
}


void display_creature()
{
	std::cout<<"\nChoose:\n\n"
		 	 <<"a) Barbarian\n"
		  	 <<"b) BlueMen\n"
		 	 <<"c) HarryPotter\n"
		 	 <<"d) Medusa\n"
		 	 <<"e) Vampires\n";

}