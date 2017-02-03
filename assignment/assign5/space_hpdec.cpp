#include "space_hpdec.h"
#include "def.h"
space_hpdec::space_hpdec(){
	type_name="hp decrease";
	type=11;
	left=right=up=down=0;
}
bool space_hpdec::move_to(player* const p){
	printf("You got into a hp decrease room!  You lose 10 hp!\n");
	p->hp-=10;
	return true;
}