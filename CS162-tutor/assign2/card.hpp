#ifndef CARD_HPP
#define CARD_HPP

class Card{
	private:
		int rank;
		int suit;
	public:
		Card();
		void set_rank(int);
		void set_suit(int);
		int get_rank();
		int get_suit();
};/*End Card class*/

#endif
