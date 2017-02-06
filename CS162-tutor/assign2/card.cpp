#include <iostream>
#include "card.hpp"

using namespace std;

Card::Card(){
	rank = -1;
	suit = -1;
}/*End Card :: Card class*/

void Card::set_rank(int r){
	rank = r;
}/*End Card :: set_rank function*/

void Card::set_suit(int s){
	suit = s;
}/*End Card :: set_suit function*/

int Card::get_rank(){
	return rank;
}/*End Card :: get_rank function*/

int Card::get_suit(){
	return suit;
}/*End Card :: get_suit function*/
