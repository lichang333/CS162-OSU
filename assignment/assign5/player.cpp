#include "player.h"
#include "space.h"
player::player(int time){
	hp=10;
	done=false;
	this->time=time;
	item_list=(item*)malloc(sizeof(item)*10);
	for (int i=0;i<10 ;i++ )
	{
		item_list[i].hp=-1;
	}
}
void player::menu()
{
	player *pp=this;
	//infos:
	while(1){
		printf("You still stay in the buring space ship! Self destruction in %d min!\n",time);
		printf("You still have %d health points\n",hp);
		printf("You are now in the %s room\n",current_room->type_name);
		if (current_room->left!=0)
		{
			printf("- This room have left door\n");
		}
		if (current_room->right!=0)
		{
			printf("- This room have right door\n");
		}
		if (current_room->up!=0)
		{
			printf("- This room have front door\n");
		}
		if (current_room->down!=0)
		{
			printf("- This room have back door\n");
		}
		printf("You have these items:\n",current_room->type_name);
		for (int i=0;i<10 ;i++ )
		{
			if (item_list[i].hp!=-1)
			{
				printf("- [%d] %d HP medical\n",i,item_list[i].hp);
			}
			else
				printf("- [%d] Empty\n",i,item_list[i].hp);
		}
		//actions:
		printf("Please choose your action(move to room by l(eft)/r(ight)/f(ront)/b(ack) or use the item by id(0~9):\n");
		char inp;
		char waste;
		inp=getchar();
		for(;(waste=getchar())!='\n';)  
		//response
		if (inp=='l')
		{
			if (current_room->left!=0&&current_room->left->move_to(this))
			{
				current_room=current_room->left;
				time-=10;
			}
		}
		if (inp=='r')
		{
			if (current_room->right!=0&&current_room->right->move_to(this))
			{
				current_room=current_room->right;
				time-=10;
			}
		}
		if (inp=='f')
		{
			if (current_room->up!=0&&current_room->up->move_to(this))
			{
				current_room=current_room->up;
				time-=10;
			}
		}
		if (inp=='b')
		{
			if (current_room->down!=0&&current_room->down->move_to(this))
			{
				current_room=current_room->down;
				time-=10;
			}
		}	
		if (inp>='0' && inp<='9')
		{
			if (item_list[inp-'0'].hp!=-1)
			{
				printf("[info]You successflly use item(+ %dhp),cost 1 min;\n",item_list[inp-'0'].hp);
				hp+=item_list[inp-'0'].hp;
				item_list[inp-'0'].hp=-1;
				time=time-1;
			}
			else
				printf("[Failed]No item here!\n");
		}

		if (hp<0)
		{
			printf("[game over]YOU DIED!\n");
			break;
		}
		if (time<0)
		{
			printf("[game over]YOU run out of time! BOMB!\n");
			break;
		}
		if (done)
		{
			printf("[SUCCESS]Congratulation!\n");
			break;
		}
		//some space
		printf("\n\n\n");
	}
}