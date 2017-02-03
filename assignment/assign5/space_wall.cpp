#include "space_wall.h"
#include "def.h"
space_wall::space_wall(){
	type_name="Wall";
	type=3;
	left=right=up=down=0;
}
bool space_wall::move_to(player* const p){
	printf("You put your face to the wall! It's too strong! You hurt your self(-1hp)!");
	p->hp-=1;
	return false;
}