#ifndef DECK_HPP
#define DECK_HPP

#include "card.hpp"

class Deck{
	private:
		Card cards[52];
		int n_cards;
	public:
		void set_cards();
		void print_cards();
		void shuffle_deck();
		Card Draw_out_from_deck();
};/*End Deck class*/

#endif
