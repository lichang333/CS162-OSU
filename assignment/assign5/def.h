#ifndef _d_
#define _d_ 1
#include "item.h"
class player;
class space
{
	public:
		space(){};
		~space(){};
		space* left;
		space* right;
		space* up;
		space* down;
		char* type_name;
		int   type;
		virtual 	bool move_to(player* const p){};
};
class player
{
	public:
		player(int time);
		int hp;
		bool done;
		item* item_list;
		space* current_room;
		int time;
		void menu();
};
#endif