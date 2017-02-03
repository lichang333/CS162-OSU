#include "ants.h"

ants::ants(critter*** map, int rows,int cols, int x,int y)
{
	this->map[0]=map[0];
	this->map[1]=map[1];
	this->rows=rows;
	this->cols=cols;
	this->x=x;
	this->y=y;
	this->type='O';
	this->breed_need=3;
}
void ants::move(int target){
	
	int x=this->x,y=this->y;
	switch (target)
	{
		case 0:
			y=this->y-1;
			break;
		case 1:
			x=this->x-1;
			break;
		case 2:
			y=this->y+1;
			break;
		case 3:
			x=this->x+1;
			break;
		default:
			break;
	}
	//printf("(%d,%d)=%d>(%d,%d)\n", this->x,this->y,target,x,y);
	if (this->check_edge(x,y))
	{
		this->move_to(x,y);
	}
}
void ants::breed(){
	//calculate which are avaliable
	int avaliable[4]={0};int total=0;
	for (int i=0;i<4 ;i++ )
	{
		int x=this->x,y=this->y;
		int i0=i;
		switch (i0)
		{
			case 0:
				y=this->y-1;
				break;
			case 1:
				x=this->x-1;
				break;
			case 2:
				y=this->y+1;
				break;
			case 3:
				x=this->x+1;
				break;
			default:
				break;
		}
		if (this->check_edge(x,y))
		{
			avaliable[i]=1;
			total++;
		}
	}
	if (total>0){
		//random from avaliable target
		int target_id=rand()%total;
		int target;

		for (int i=0;i<4 ;i++ ){
			if (avaliable[i]==1)
			{
				target_id--;
			}
			if (target_id<0)
			{
				target=i;
				break;
			}
		}
		//calculate final target
		int x=this->x,y=this->y;
		switch (target)
		{
			case 0:
				y=this->y-1;
				break;
			case 1:
				x=this->x-1;
				break;
			case 2:
				y=this->y+1;
				break;
			case 3:
				x=this->x+1;
				break;
			default:
				break;
		}	
		
		if (this->check_edge(x,y))
		{
			//spawn new ant
			this->new_map()[x*(this->cols)+y]=new ants(this->map,this->rows,this->cols,x,y);
			printf("ant(%d,%d) breed ant(%d,%d) \n",this->x,this->y,x,y );			
		}	
		this->survive_time=0;
	}
}