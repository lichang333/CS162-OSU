#include "space_end.h"
#include "def.h"
space_end::space_end(){
	type_name="Escape pod";
	type=2;
	left=right=up=down=0;
}
bool space_end::move_to(player* const p){
	printf("You successfully get into escape pod! You are safe now!\n");
	p->done=true;
	return true;
}