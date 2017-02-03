#include "space.h"
#include "space_end.h"
#include "space_start.h"
#include "space_hpinc.h"
#include "space_hpdec.h"
#include "space_item.h"
#include "space_wall.h"
#include "player.h"
#include "item.h"
int main(int argc,char* argv[])
{
	space* room[8];
	//rooms
	//map
	/*
	s-i-w-d-e
	  |   |
	  t-t-d
	*/
	room[0]=new space_start();
	room[1]=new space_hpinc();
	room[2]=new space_wall();
	room[3]=new space_hpdec();
	room[4]=new space_end();
	room[5]=new space_item();
	room[6]=new space_item();
	room[7]=new space_hpdec();
	room[0]->right=room[1];
	room[1]->right=room[2];
	room[2]->right=room[3];
	room[3]->right=room[4];

	room[1]->left=room[0];
	room[2]->left=room[1];
	room[3]->left=room[2];
	room[4]->left=room[3];

	room[1]->down=room[5];
	room[5]->right=room[6];
	room[6]->right=room[7];
	room[7]->up=room[3];
	player* p=new player(80);
	p->current_room=room[0];
	p->menu();
	return 0;
}