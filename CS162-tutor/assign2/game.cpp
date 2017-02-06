#include <iostream>

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"

using namespace std;


class Game{
	private:
		Deck cards;
		Player players[2];
	public:
		Game();
		void start_turn();
		void player_earn_books();
		void computer_earn_books();
		void user_turn();
		void computer_turn;
}/*End Game class*/

Game::Game(){
	cards.set_cards();
	cards.shuffle_deck();
}/*End Game class constructor*/

void Game::player_earn_books(){
	int Ace = 0,  Two = 0,  Three = 0,  Four = 0,  Five = 0,
            Six = 0,  Seven = 0,   Eight = 0,   Nine = 0,   Ten = 0,
            Jack = 0,   Queen = 0,    King = 0;
	for(int i = 0; i < 1000; i++){
		if(player[0].get_hand_cards_rank(i) == 0){ Ace++; }
		else if(player[0].get_hand_cards_rank(i) == 1){ Two++; }
		else if(player[0].get_hand_cards_rank(i) == 2){ Three++; }
		else if(player[0].get_hand_cards_rank(i) == 3){ Four++; }
		else if(player[0].get_hand_cards_rank(i) == 4){ Five++; }
		else if(player[0].get_hand_cards_rank(i) == 5){ Six++; }
		else if(player[0].get_hand_cards_rank(i) == 6){ Seven++; }
		else if(player[0].get_hand_cards_rank(i) == 7){ Eight++; }
		else if(player[0].get_hand_cards_rank(i) == 8){ Nine++; }
		else if(player[0].get_hand_cards_rank(i) == 9){ Ten++; }
		else if(player[0].get_hand_cards_rank(i) == 10){ Jack++; }
		else if(player[0].get_hand_cards_rank(i) == 11){ Queen++; }
		else if(player[0].get_hand_cards_rank(i) == 12){ King++; }
	}/*End for loop*/
        if(     Ace   >= 4){ player[0].get_books(0,1); }
        else if(Two   >= 4){ player[0].get_books(1,1); }
        else if(Three >= 4){ player[0].get_books(2,1); }
        else if(Four  >= 4){ player[0].get_books(3,1); }
        else if(Five  >= 4){ player[0].get_books(4,1); }
        else if(Six   >= 4){ player[0].get_books(5,1); }
        else if(Seven >= 4){ player[0].get_books(6,1); }
        else if(Eight >= 4){ player[0].get_books(7,1); }
        else if(Nine  >= 4){ player[0].get_books(8,1); }
        else if(Ten   >= 4){ player[0].get_books(9,1); }
        else if(Jack  >= 4){ player[0].get_books(10,1); }
        else if(Queen >= 4){ player[0].get_books(11,1); }
        else if(King  >= 4){ player[0].get_books(12,1); }
}/*End player earn books class function*/

void Game::computer_earn_books(){
	int Ace = 0,  Two = 0,  Three = 0,  Four = 0,  Five = 0,
            Six = 0,  Seven = 0,   Eight = 0,   Nine = 0,   Ten = 0,
            Jack = 0,   Queen = 0,    King = 0;
	for(int i = 0; i < 1000; i++){
		if(player[1].get_hand_cards_rank(i) == 0){ Ace++; }
		else if(player[1].get_hand_cards_rank(i) == 1){ Two++; }
		else if(player[1].get_hand_cards_rank(i) == 2){ Three++; }
		else if(player[1].get_hand_cards_rank(i) == 3){ Four++; }
		else if(player[1].get_hand_cards_rank(i) == 4){ Five++; }
		else if(player[1].get_hand_cards_rank(i) == 5){ Six++; }
		else if(player[1].get_hand_cards_rank(i) == 6){ Seven++; }
		else if(player[1].get_hand_cards_rank(i) == 7){ Eight++; }
		else if(player[1].get_hand_cards_rank(i) == 8){ Nine++; }
		else if(player[1].get_hand_cards_rank(i) == 9){ Ten++; }
		else if(player[1].get_hand_cards_rank(i) == 10){ Jack++; }
		else if(player[1].get_hand_cards_rank(i) == 11){ Queen++; }
		else if(player[1].get_hand_cards_rank(i) == 12){ King++; }
	}/*End for loop*/
        if(     Ace   >= 4){ player[1].get_books(0,1); }
        else if(Two   >= 4){ player[1].get_books(1,1); }
        else if(Three >= 4){ player[1].get_books(2,1); }
        else if(Four  >= 4){ player[1].get_books(3,1); }
        else if(Five  >= 4){ player[1].get_books(4,1); }
        else if(Six   >= 4){ player[1].get_books(5,1); }
        else if(Seven >= 4){ player[1].get_books(6,1); }
        else if(Eight >= 4){ player[1].get_books(7,1); }
        else if(Nine  >= 4){ player[1].get_books(8,1); }
        else if(Ten   >= 4){ player[1].get_books(9,1); }
        else if(Jack  >= 4){ player[1].get_books(10,1); }
        else if(Queen >= 4){ player[1].get_books(11,1); }
        else if(King  >= 4){ player[1].get_books(12,1); }
}/*End computer earn books class function*/

void Game::user_turn(){
	int select_num = 0 , draw_card_end = 1 , i = j = k = 0;
	int error_check = 0;
	int Ace = 0,  Two = 0,  Three = 0,  Four = 0,  Five = 0,
            Six = 0,  Seven = 0,   Eight = 0,   Nine = 0,   Ten = 0,
            Jack = 0,   Queen = 0,    King = 0;
while(draw_card_end == 1){
	i = j = k = 0;
	for(i = 0; i < 1000; i++){
		if(player[0].get_hand_cards_rank(i) == 0){ Ace++; }
		else if(player[0].get_hand_cards_rank(i) == 1){ Two++; }
		else if(player[0].get_hand_cards_rank(i) == 2){ Three++; }
		else if(player[0].get_hand_cards_rank(i) == 3){ Four++; }
		else if(player[0].get_hand_cards_rank(i) == 4){ Five++; }
		else if(player[0].get_hand_cards_rank(i) == 5){ Six++; }
		else if(player[0].get_hand_cards_rank(i) == 6){ Seven++; }
		else if(player[0].get_hand_cards_rank(i) == 7){ Eight++; }
		else if(player[0].get_hand_cards_rank(i) == 8){ Nine++; }
		else if(player[0].get_hand_cards_rank(i) == 9){ Ten++; }
		else if(player[0].get_hand_cards_rank(i) == 10){ Jack++; }
		else if(player[0].get_hand_cards_rank(i) == 11){ Queen++; }
		else if(player[0].get_hand_cards_rank(i) == 12){ King++; }
	}/*End for loop*/

	if(     Ace   >= 1){ cout << "1. Ace" << endl; }
	else if(Two   >= 1){ cout << "2. Two" << endl; }
	else if(Three >= 1){ cout << "3. Three" << endl; }
	else if(Four  >= 1){ cout << "4. Four" << endl; }
	else if(Five  >= 1){ cout << "5. Five" << endl; }
	else if(Six   >= 1){ cout << "6. Six" << endl; }
	else if(Seven >= 1){ cout << "7. Seven" << endl; }
	else if(Eight >= 1){ cout << "8. Eight" << endl; }
	else if(Nine  >= 1){ cout << "9. Nine" << endl; }
	else if(Ten   >= 1){ cout << "10. Ten" << endl; }
	else if(Jack  >= 1){ cout << "11. Jack" << endl; }
	else if(Queen >= 1){ cout << "12. Queen" << endl; }
	else if(King  >= 1){ cout << "13. King" << endl; }

	cout << "Make your choice: ";
	while(error_check == 0){
		cin >> select_num;
		if(     select_num == 1 &&    Ace >= 1){ error_check = 1; }
		else if(select_num == 2 &&    Two >= 1){ error_check = 1; }
		else if(select_num == 3 &&  Three >= 1){ error_check = 1; }
		else if(select_num == 4 &&   Four >= 1){ error_check = 1; }
		else if(select_num == 5 &&   Five >= 1){ error_check = 1; }
		else if(select_num == 6 &&    Six >= 1){ error_check = 1; }
		else if(select_num == 7 &&  Seven >= 1){ error_check = 1; }
		else if(select_num == 8 &&  Eight >= 1){ error_check = 1; }
		else if(select_num == 9 &&   Nine >= 1){ error_check = 1; }
		else if(select_num == 10 &&   Ten >= 1){ error_check = 1; }
		else if(select_num == 11 &&  Jack >= 1){ error_check = 1; }
		else if(select_num == 12 && Queen >= 1){ error_check = 1; }
		else if(select_num == 13 &&  King >= 1){ error_check = 1; }
	}/*End while loop*/

	for(i = 0; i < 1000; i++){
		if(player[0].get_hand_cards_rank(i) != -2){ j++; }
	}/*End for loop*/

	for(i = 0; i < 1000; i++){
		if(player[1].get_hand_cards_rank(i) == select_num - 1){
			player[1].set_cards_rank(i , -1);
			player[1].set_cards_suit(i , -1);
			player[0].set_cards_rank(j, select_num - 1);
			player[0].set_cards_suit(j, select_num - 1);
			k++;
		}/*End if loop*/
	}/*End for loop*/
	if(k != 0){
		player[0].print_cards();
		player_earn_books();
		cout << "You have " << player[0].calc_total_books << " books." << endl;
	}/*End if loop*/
	else if(k == 0)
		cout << "Go fish!" << endl;




	player_earn_books();
	cout << "You have " << player[0].calc_total_books << " books." << endl;
}/*End while loop*/
}/*End user turn class function*/

void Game::computer_turn(){
	int select_num = 0 , draw_card_end = 1 , i = j = k = 0;
	int Ace = 0,  Two = 0,  Three = 0,  Four = 0,  Five = 0,
            Six = 0,  Seven = 0,   Eight = 0,   Nine = 0,   Ten = 0,
            Jack = 0,   Queen = 0,    King = 0;
	srand(time(NULL));
while(draw_card_end == 1){
	i = j = k = 0;
	cout << "Now is computer's turn!" << endl;
	
	do{
		select_num = rand() % 13;
	}while(player[1].get_hand_cards_rank(select_num) != -1 && player[1].get_hand_cards_rank(select_num) != -2);

	cout << "Computer want to get your: ";
		if(player[1].get_hand_cards_rank(select_num) == 0){ cout << "Ace." << endl; }
		else if(player[1].get_hand_cards_rank(select_num) == 1){ cout << "Two." << endl; }
		else if(player[1].get_hand_cards_rank(select_num) == 2){ cout << "Three." << endl; }
		else if(player[1].get_hand_cards_rank(select_num) == 3){ cout << "Four." << endl; }
		else if(player[1].get_hand_cards_rank(select_num) == 4){ cout << "Five." << endl; }
		else if(player[1].get_hand_cards_rank(select_num) == 5){ cout << "Six." << endl; }
		else if(player[1].get_hand_cards_rank(select_num) == 6){ cout << "Seven." << endl; }
		else if(player[1].get_hand_cards_rank(select_num) == 7){ cout << "Eight." << endl; }
		else if(player[1].get_hand_cards_rank(select_num) == 8){ cout << "Nine." << endl; }
		else if(player[1].get_hand_cards_rank(select_num) == 9){ cout << "Ten." << endl; }
		else if(player[1].get_hand_cards_rank(select_num) == 10){ cout << "Jack." << endl; }
		else if(player[1].get_hand_cards_rank(select_num) == 11){ cout << "Queen." << endl; }
		else if(player[1].get_hand_cards_rank(select_num) == 12){ cout << "King." << endl; }

		for(i = 0; i < 1000; i++){
			if(player[1].get_hand_cards_rank(i) != -2)
				j++;
		}/*End for loop*/
		for(i = 0; i < 1000; i++){
			if(player[0].get_hand_cards_rank(i) == select_num - 1){
				player[0].set_cards_rank(i , -1);
				player[0].set_cards_suit(i , -1);
				player[1].set_cards_rank(j, select_num - 1);
				player[1].set_cards_suit(j, select_num - 1);
				k++;
			}/*End if loop*/
		}/*End for loop*/
		if(k != 0)
			player[1].print_cards();
		else if(k == 0)
			cout << "Go fish!" << endl;

}/*End while loop*/
}/*End computer turn class function*/

void Game::start_turn(){
	int game_over = 1;
	while(game_over == 1){
		int count_all_books = 0;
		while(count_all_books < 13){
			user_turn();
			count_all_books = player[0].calc_total_books() 
					+ player[1].calc_total_books();
			if(count_all_books >= 13) { break; }
			computer_turn();
			count_all_books = player[0].calc_total_books() 
					+ player[1].calc_total_books();
		}/*End while loop*/
		if(player[0].calc_total_books > player[1].calc.total_books)
			cout << "You win the game!" << endl;
		else if(player[0].calc_total_books < player[1].calc_total_books)
			cout << "Computer win the game, you lost :(" << endl;
		cout << "******************************************" << endl;
		cout << "Countine the game? 1-Yes  2-No -------------->     " << endl;
		cin >> game_over;
	}/*End while loop*/
}/*End start turn class function*/

