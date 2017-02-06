#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "hand.hpp"

class Player{
	private:
		Hand hand;
		int* books;
		int n_books;
	public:
		player();/* Constructor*/
		~player();/* Destructor*/
		int calc_total_books();
		void earn_books();
//		void user_turn();
//		void opponnent_turn();
		int get_n_cards();
		int get_n_books();
		int get_hand_cards_rank(int i);
		int get_books(int i, int j);
};/*End Player class*/

#endif
