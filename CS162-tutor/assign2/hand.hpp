#ifndef HAND_HPP
#define HAND_HPP

#include "card.hpp"
//#include "deck.hpp"

class Hand{
	private:
//		Card* cards;
		Card cards[1000];
		int n_cards;
	public:
		Hand();
//		~Hand();
		void draw_cards(Card card);
		void print_cards();
		int get_cards_rank(int i);
		void set_cards_rank(int i, int j);
		void set_cards_suit(int i, int j);
		int get_n_cards();

};/*End Hand class*/

#endif
