#include "space_item.h"
#include "def.h"
space_item::space_item(){
	type_name="Storage room";
	type=3;
	left=right=up=down=0;
}
bool space_item::move_to(player* const p){
	printf("You got into a storage room!  You can take a hp medical!\n");

	while (1)
	{
		printf("Get it at which space?(0-9 for space,- for give up)\n");
		char inp;
		char waste;
		inp=getchar();
		for(;(waste=getchar())!='\n';)  
		if (inp=='-')
		{
			break;
		}
		if (inp>='0' && inp<='9')
		{
			if (p->item_list[inp-'0'].hp!=-1)
			{
				printf("[failed]Not empty!\n");
			}
			else
			{
				p->item_list[inp-'0'].hp=6;
				break;
			}
		}
	}
	return true;
}