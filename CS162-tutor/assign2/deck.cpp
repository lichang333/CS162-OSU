#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "deck.hpp"
#include "card.hpp"

using namespace std;

void Deck::set_cards(){
	n_cards = 52;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 13; j++){
			cards[i * 13 + j].set_suit(i);
			cards[i * 13 + j].set_rank(j);
		}/*End for loop*/
	}/*End for loop*/
}/*End Deck::set_cards class*/

void Deck::print_cards(){
	for(int i = 0; i< 52; i++){
		cout << "Rank: " << cards[i].get_rank() + 1 << " - " 
		     << "Suit: " << cards[i].get_suit() + 1 << endl;
	}/*End for loop*/

}/*End Deck::get_cards function*/

void Deck::shuffle_deck(){
	srand(time(NULL));
	random_shuffle(cards, cards + 52);
}/*End shuffle_deck function*/

Card Deck::Draw_out_from_deck(){
	n_cards--;
	return cards[n_cards];
}/*End Draw out from deck function*/
