#include <iostream>

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"

using namespace std;

int main(){

	Card my_card;
	Deck initialize_game;
	Hand p1;
	Hand p2;

	my_card.set_rank(13);
	my_card.set_suit(4);
//	cout << my_card.get_rank() << endl;
//	cout << my_card.get_suit() << endl;

	/* Initial game before start. To create 52 cards and random shuffle it.*/

	initialize_game.set_cards();
	initialize_game.shuffle_deck();
//	initialize_game.print_cards();
//	p1.draw_cards(initialize_game.Draw_out_from_deck());

	/* It will happen for each player to draw 7 cards from the deck */

	for(int i = 0; i < 7; i++){
		p1.draw_cards(initialize_game.Draw_out_from_deck());
		p2.draw_cards(initialize_game.Draw_out_from_deck());
	}/*End for loop*/

	p1.print_cards();
	p2.print_cards();


	return 0;
}
