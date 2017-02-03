#include "critter.h"
#include <stdlib.h>
#include <stdio.h>
bool critter::check_edge(int x,int y){
	if (x<0) 
		return false;
	if (x>=this->rows)
		return false;
	if (y<0) 
		return false;
	if (y>=this->cols)
		return false;
	if ((this->old_map()[x*(this->cols)+y])!=Null)
		return false;
	return true;
}
void critter::swap_map(){
	if (this==Null) return;
	this->active_buffer=1-this->active_buffer;
}
critter** critter::old_map(){return this->map[this->active_buffer];}
critter** critter::new_map(){return this->map[1-this->active_buffer];}
//init the map memory by rows and cols
critter*** critter::init_map(int rows,int cols){
	critter*** map=(critter***)malloc(sizeof(critter**)*2);
	map[0]=(critter**)malloc(sizeof(critter*)*rows*cols);
	map[1]=(critter**)malloc(sizeof(critter*)*rows*cols);
	this->map[0]=map[0];
	this->map[1]=map[1];
	this->cols=cols;
	this->rows=rows;
	return map;
}
void critter::move_to(int _x,int _y)
{


	printf("Critter (%d,%d)=>(%d,%d)\n", this->x,this->y,_x,_y);
	(this->new_map())[(this->x)*(this->cols)+(this->y)]=NULL;
	(this->new_map())[_x*(this->cols)+_y]=this;
	this->x=_x;
	this->y=_y;
	this->survive_time++;
	if (this->survive_time>=this->breed_need)
	{
		this->breed();
	}
}