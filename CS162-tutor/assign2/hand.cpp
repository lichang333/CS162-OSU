#include <iostream>

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"

using namespace std;

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

player -> hand;
Hand p1;
Deck initialize_game;
//p1.draw_cards(initialize_game.Draw_out_from_deck());

Hand::Hand(){
	n_cards = 0;
//	this->cards = new Card [52];
	for(int i = 0; i < 1000; i++){
		cards[i].set_suit(-2);
		cards[i].set_rank(-2);
	}/*End for loop*/
}/*End Hand class function*/

void Hand::draw_cards(Card card){
//	this->cards[n_cards] = card;
	cards[n_cards] = card;
	n_cards = 0;
	for(int i = 0; i < 1000; i++){
		if(cards[i].get_suit() >= 1 && cards[i].get_rank() >= 1){
			n_cards++;
		}/*End if loop*/
	}/*End for loop*/
}/*End draw_cards class function*/

void Hand::set_cards_rank(int i, int j){
	cards[i].set_rank(j);
}/*End set cards rank class function*/

void Hand::set_cards_suit(int i, int j){
	cards[i].set_suit(j);
}/*End set cards suit class function*/

int Hand::get_cards_rank(int i){
	return cards[i].get_rank();
}/*End get cards class function*/

int Hand::get_n_cards(){
	return n_cards;
}/*End get_n_cards class function*/
void Hand::print_cards(){
//	for(int i = 0; i < n_cards; i++){
	for(int i = 0; i < 1000; i++){
		if(cards[i].get_suit() >= 0 && cards[i].get_rank() >= 0){
			/* Cards rank print check*/
//			if(cards[i].get_rank() == 0){cout << "Rank: Ace";}
//			else if(cards[i].get_rank() == 1){cout << "Rank: Two";}
//			else if(cards[i].get_rank() == 2){cout << "Rank: Three";}
//			else if(cards[i].get_rank() == 3){cout << "Rank: Four";}
//			else if(cards[i].get_rank() == 4){cout << "Rank: Five";}
//			else if(cards[i].get_rank() == 5){cout << "Rank: Six";}
//			else if(cards[i].get_rank() == 6){cout << "Rank: Seven";}
//			else if(cards[i].get_rank() == 7){cout << "Rank: Eight";}
//			else if(cards[i].get_rank() == 8){cout << "Rank: Nine";}
//			else if(cards[i].get_rank() == 9){cout << "Rank: Ten";}
//			else if(cards[i].get_rank() == 10){cout << "Rank: Jack";}
//			else if(cards[i].get_rank() == 11){cout << "Rank: Queen";}
//			else if(cards[i].get_rank() == 12){cout << "Rank: King";}
			/*Cards suit print check*/
//			if(cards[i].get_suit() == 0){cout << " -- Suit: Spade" << endl;}
//			else if(cards[i].get_suit() == 1){cout << " -- Suit: Heart" << endl;}
//			else if(cards[i].get_suit() == 2){cout << " -- Suit: Diamond" << endl;}
//			else if(cards[i].get_suit() == 3){cout << " -- Suit: Club" << endl;}
				cout << "Rank: " << cards[i].get_rank() + 1 << " - " 
		     	     	     << "Suit: " << cards[i].get_suit() + 1 << endl;
		}/*End if loop*/
	}/*End for loop*/
}/*End print cards class function*/

//Hand::~Hand(){
//	delete[] this->cards;
//}/*End free_cards class function*/
