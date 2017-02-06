#include <iostream>
#include <cstdlib>
#include <ctime>

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"

using namespace std;

class Player{
	private:
		Hand hand;
		int* books;
		int n_books;
	public:
		Player();
		~Player();
		int calc_total_books();
		void earn_books();
		void user_turn();
		int get_n_books();
		int get_n_cards();
		int get_hand_cards_rank(int i);
		int get_books(int i, int j);
//		Hand get_books();
};



Player::player(){
	n_books = 0;
	this->books = new int [13];
	for(int i = 0; i < 13; i++)
		books[i] = -1;
}/*End Player class function*/

int Player::calc_total_books(){
	n_books = 0;
	for(int i = 0; i < 13; i++){
		if(books[i] != -1)
			n_books++;
	}/*End for loop*/
	return n_books;
}/*End calc total books class function*/

int Player::get_n_books(){
	return n_books;
}/*End get player class function*/

//int Player::get_n_cards(){
//	return hand.n_cards;
//}/*End get n cards class function*/

int Player::get_hand_cards_rank(int i){
	return hand.get_cards_rank(i);
}/*End get hand cards rank class function*/

void Player::get_books(int i, int j){
	books[i] = j;
}/*End get books class function*/

void Player::earn_books(){
	int Ace = 0,  Two = 0,	Three = 0,  Four = 0,  Five = 0,
	    Six = 0,  Seven = 0,   Eight = 0,   Nine = 0,   Ten = 0,
	    Jack = 0,   Queen = 0,    King = 0;
	for(int i = 0; i < 1000; i++){
		if(hand.get_cards_rank(i) == 0){ Ace++; }
		else if(hand.get_cards_rank(i) == 1){ Two++; }
		else if(hand.get_cards_rank(i) == 2){ Three++; }
		else if(hand.get_cards_rank(i) == 3){ Four++; }
		else if(hand.get_cards_rank(i) == 4){ Five++; }
		else if(hand.get_cards_rank(i) == 5){ Six++; }
		else if(hand.get_cards_rank(i) == 6){ Seven++; }
		else if(hand.get_cards_rank(i) == 7){ Eight++; }
		else if(hand.get_cards_rank(i) == 8){ Nine++; }
		else if(hand.get_cards_rank(i) == 9){ Ten++; }
		else if(hand.get_cards_rank(i) == 10){ Jack++; }
		else if(hand.get_cards_rank(i) == 11){ Queen++; }
		else if(hand.get_cards_rank(i) == 12){ King++; }
	}/*End for loop*/
	if(Ace >= 4){ books[0] = 1; }
	else if(Two >= 4){ books[1] = 1; }
	else if(Three >= 4){ books[2] = 1; }
	else if(Four >= 4){ books[3] = 1; }
	else if(Five >= 4){ books[4] = 1; }
	else if(Six >= 4){ books[5] = 1; }
	else if(Seven >= 4){ books[6] = 1; }
	else if(Eight >= 4){ books[7] = 1; }
	else if(Nine >= 4){ books[8] = 1; }
	else if(Ten >= 4){ books[9] = 1; }
	else if(Jack >= 4){ books[10] = 1; }
	else if(Queen >= 4){ books[11] = 1; }
	else if(King >= 4){ books[12] = 1; }
}/*End earn books class function*/

//void Player::user_turn(){
//	int select_num = 0 , draw_card_end = 1;
//	cout << "Now is your turn!" << endl;
//	cout << "You have " << hand.n_cards << " in your hand." << endl;
//	hand.print_cards();
//	cout << "What rank do you want to ask for? ";
//	int Ace = 0,
//	    Two = 0,	
//	    Three = 0,
//	    Four = 0,
//	    Five = 0,
//	    Six = 0,
//	    Seven = 0,
//	    Eight = 0,
//	    Nine = 0,
//	    Ten = 0,
//	    Jack = 0,
//	    Queen = 0,
//	    King = 0;
//	for(int i = 0; i < 1000; i++){
//		if(hand.cards[i].get_rank() == 0){ Ace++; }
//		else if(hand.cards[i].get_rank() == 1){ Two++; }
//		else if(hand.cards[i].get_rank() == 2){ Three++; }
//		else if(hand.cards[i].get_rank() == 3){ Four++; }
//		else if(hand.cards[i].get_rank() == 4){ Five++; }
//		else if(hand.cards[i].get_rank() == 5){ Six++; }
//		else if(hand.cards[i].get_rank() == 6){ Seven++; }
//		else if(hand.cards[i].get_rank() == 7){ Eight++; }
//		else if(hand.cards[i].get_rank() == 8){ Nine++; }
//		else if(hand.cards[i].get_rank() == 9){ Ten++; }
//		else if(hand.cards[i].get_rank() == 10){ Jack++; }
//		else if(hand.cards[i].get_rank() == 11){ Queen++; }
//		else if(hand.cards[i].get_rank() == 12){ King++; }
//	}/*End for loop*/
//	if(Ace >= 1){ cout << "1. Ace" << endl; }
//	else if(Two >= 1){ cout << "2. Two" << endl; }
//	else if(Three >= 1){ cout << "3. Three" << endl; }
//	else if(Four >= 1){ cout << "4. Four" << endl; }
//	else if(Five >= 1){ cout << "5. Five" << endl; }
//	else if(Six >= 1){ cout << "6. Six" << endl; }
//	else if(Seven >= 1){ cout << "7. Seven" << endl; }
//	else if(Eight >= 1){ cout << "8. Eight" << endl; }
//	else if(Nine >= 1){ cout << "9. Nine" << endl; }
//	else if(Ten >= 1){ cout << "10. Ten" << endl; }
//	else if(Jack >= 1){ cout << "11. Jack" << endl; }
//	else if(Queen >= 1){ cout << "12. Queen" << endl; }
//	else if(King >= 1){ cout << "13. King" << endl; }

//	cout << "Make your choice: ";
//	cin >> select_num;

//	while(draw_card_end == 1){
//		if{}/* 要卡*/
//		else{
//			cout << "Go fish!" << endl;
//			/* 抽的卡和所问的卡rank不相同时*/
//			/*否则继续向对面要卡*/
				
//			draw_card_end = 0;
//		}/*End else loop*/
//	}/*End while loop*/

//	/*手牌空了，补牌*/
//	if(Ace == Two == Three == Four == Five == Six == Seven ==
//	   Eight == Nine == Ten == Jack == Queen == King == 0)
//}/*End user_turn class function*/

//void Player::opponent_turn(){
//	srand(time(NULL));
//	int i = 0;
//	cout << "Now is computer's turn!" << endl;
//	cout << "Computer has " << hand.n_cards << " in this deck." << endl;
//
//	while(hands.cards[i].get_rank() != -1 && hands.cards[i].get_rank() != -2){
//		i = rand() % 13;
//	}/*End while loop*/
//	cout << "Computer want to get your ";
//		if(hand.cards[i].get_rank() == 0){ cout << "Ace." << endl;}
//		else if(hand.cards[i].get_rank() == 1){ cout << "Two." << endl; }
//		else if(hand.cards[i].get_rank() == 2){ cout << "Three." << endl; }
//		else if(hand.cards[i].get_rank() == 3){ cout << "Four." << endl; }
//		else if(hand.cards[i].get_rank() == 4){ cout << "Five." << endl; }
//		else if(hand.cards[i].get_rank() == 5){ cout << "Six." << endl; }
//		else if(hand.cards[i].get_rank() == 6){ cout << "Seven." << endl; }
//		else if(hand.cards[i].get_rank() == 7){ cout << "Eight." << endl; }
//		else if(hand.cards[i].get_rank() == 8){ cout << "Nine." << endl; }
//		else if(hand.cards[i].get_rank() == 9){ cout << "Ten." << endl; }
//		else if(hand.cards[i].get_rank() == 10){ cout << "Jack." << endl; }
//		else if(hand.cards[i].get_rank() == 11){ cout << "Queen." << endl; }
//		else if(hand.cards[i].get_rank() == 12){ cout << "King." << endl; }
//
//	else{
//		cout << "Go fish!" << endl;
//		/*抽的卡和向对面要的卡rank不相同时*/
//		/*否则继续向对面要卡*/
//		draw_card_end = 0;
//
//}/*End opponent turn class function*/
Player::~player(){
	delete[] this->books;
}/*End Player class function*/
