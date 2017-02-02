#include "card.h"

class deck
{
private:
	card cards[52];
	int given_cards_num;

public:
	deck();

	void set_deck();

	~deck();

	void display();

	void shuffle();

	void renew();
};
