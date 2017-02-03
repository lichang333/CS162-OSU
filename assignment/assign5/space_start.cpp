#include "space_start.h"
#include "def.h"
space_start::space_start(){
	type_name="Wake Up room";
	type=1;
	left=right=up=down=0;
}
bool space_start::move_to(player* const p){
	printf("You got into your Wake Up room! \n");
	return true;
}