#ifndef GAME_HPP
#define GAME_HPP

#include "deck.hpp"
#include "player.hpp"

class Game{
	private:
		Deck cards;
		Player players[2];
	public:
		Game();
		void user_turn();
		void computer_turn();
		void player_earn_books();
		void computer_earn_books();
		void start_turn();
}/*End Game class

#endif
