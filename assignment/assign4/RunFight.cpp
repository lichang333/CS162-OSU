#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "RunFight.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

int RunFight::get_win_points()
{
    return 2;
}

RunFight::RunFight(Queue *s1, Queue *s2,int num_sims)
{
    srand(time(0));
    side1 = s1;
    side2 = s2;

    losers1 = new Stack;
    losers2 = new Stack;
    losers = new Stack;

    cur_sim = 0;
    side1pts = 0;
    side2pts = 0;
}

RunFight::~RunFight()
{
    delete losers1;
    delete losers2;
    delete losers;
}


int RunFight::run_tournament()
{
    Creature *p1;    
    Creature *p2;

    std::cout<<"============Battle!============"<<std::endl;

    while (true)
    {

        if (!(p1 = side1->remove()))   //if side 1 lose
        {
            // std::cout<<"=======2nd while loop======="<<std::endl;
            bool p2_flag=false;
            while ((p2 = side2->remove()))
            {
                p2_flag=true;
            //    losers2->add(p2);
               // losers->add(p2);
                // side2pts += (p2->get_win_points());

              //  side2pts += 2;
              //  side1pts -= 1;
            //    std::cout<<">>Team 2 "<<p2->name<<" win this round("<<side1pts<<" vs "<<side2pts<<").\n\n";
                // std::cout<<p2->get_win_points()<<std::endl;

                defeat_sides.push_back(2);
            }
            if (p2_flag)
                return p2_win;
            else
                return 2;
        }

        else if (!(p2 = side2->remove()))     //if side 2 lose
        {
            while ((p1 = side1->remove()))
            {
              //  losers1->add(p1);
              //  losers->add(p1);
                // side1pts += (p1->get_win_points());

               // side1pts += 2;
               // side2pts -= 1;
             //   std::cout<<">>Team 1 "<<p1->name<<" win this round("<<side1pts<<" vs "<<side2pts<<").\n\n";
                // std::cout<<p1->get_win_points()<<std::endl;

                defeat_sides.push_back(1);
            }

            return p1_win;
        }

        else
        {

            int result = play_match(p1, p2);

            if (result == p1_win)
            {


                p1->revive();


                side1->add(p1);

                losers2->add(p2);
                losers->add(p2);
                // side2pts += (p2->get_win_points());
                side1pts += 2; //win +2
                side2pts -= 1; //lose -1
                std::cout<<">>Team 1 "<<p1->name<<" win this round(  "<<side1pts<<" | "<<side2pts<<"  ).\n\n";
                defeat_sides.push_back(2);
            }
            else if (result == p2_win)
            {

                p2->revive();
                side2->add(p2);
                losers1->add(p1);
                losers->add(p1);
                // side1pts += (p1->get_win_points());
                side1pts -= 1;  //win +2
                side2pts += 2;  //lose -1
                std::cout<<">>Team 2 "<<p2->name<<" win this round(  "<<side1pts<<" | "<<side2pts<<"  ).\n\n";
                defeat_sides.push_back(1);
            }
            else   //DRAW
            {
                losers2->add(p2);
                losers1->add(p1);
                losers->add(p1);
                losers->add(p2);
                side1pts += 1;
                side2pts += 1;
                std::cout<<"DRAW!! (  "<<side1pts<<" | "<<side2pts<<"  ).\n\n";
                defeat_sides.push_back(1);                
            }
        }
    }
}


bool RunFight::run_simulation()
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



void RunFight::print_outcome()
{


    bool winner = run_tournament();

    if (winner == p1_win)
        std::cout << "\n Team 1 WIN!!\n\n";
    else if (winner == p2_win)
        std::cout << "\n Team 2 WIN!!\n\n";
    else
        std::cout << "Equal!\n\n";

    // display team KO point total
    std::cout << "Total Points\n" <<
                 "Player 1: " << side1pts << '\n' <<
                 "Player 2: " << side2pts << "\n\n";

    // print top three finishers
    print_top_three();
}


int RunFight::get_result()
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



int RunFight::play_match(Creature* p1, Creature* p2)
{
    ++cur_sim;


    bool p1_achilles_cut = false;
    bool p2_achilles_cut = false;

        // int ROUND__BATTLE = 1;
        // std::cout<<"ROUND "<<ROUND__BATTLE<<":\n";
        // ROUND__BATTLE++;
    std::cout<<"P1: "<<p1->name<<" |VS| "<<"P2: "<<p2->name<<" :\n";

    while (true)
    {
        // player 1 attacks player 2
        int p1_attack = p1->attack();
        int p2_defense = p2->defense();

        //P2 take damage
        p2->damage_take(p1_attack, p2_defense);
        
 

        // player 2 attacks player 1
        int p2_attack = p2->attack();
        int p1_defense = p1->defense();

        //P1 take damage
        p1->damage_take(p2_attack, p1_defense);
            //if p2 dead, p1 win
        if (p2->dead() &&(!(p1->dead())))
        {

            
            // side1pts += 2;
            return p1_win;
        }   
        //if p1 dead, p2 win
        if (p1->dead()&&(!(p2->dead())))
        {
            
            // side2pts += 2;
            return p2_win;
        }

        if (p1->dead() && p2->dead())
        {
            
            return 2;
        }


        
    }
}


void RunFight::print_top_three()
{
    std::cout << "=============================== \n";
    std::cout << "Top 3 of the idot: \n";
    int end_vec = defeat_sides.size();

    // get the top 3 losers.
    for (int i = 1; i <= 3; ++i)
    {
        //which team from
        int plyr_num = defeat_sides.at(end_vec - i);

        std::cout << i << ") [P" << plyr_num  <<"]"<<
                     (losers->remove())->get_name() << '\n';
    }
}


