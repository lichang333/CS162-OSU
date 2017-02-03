#include "space_hpinc.h"
#include "def.h"
space_hpinc::space_hpinc(){
	type_name="hp increase";
	type=11;
	left=right=up=down=0;
}
bool space_hpinc::move_to(player* const p){
	printf("You got into a hp increase room!  You get 10 hp!\n");
	p->hp+=10;
	return true;
}