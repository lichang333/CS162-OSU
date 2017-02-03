#include "doodlebugs.h"
doodlebugs::doodlebugs(critter*** map, int rows,int cols, int x,int y)
{
	this->map[0]=map[0];
	this->map[1]=map[1];
	this->rows=rows;
	this->cols=cols;
	this->x=x;
	this->y=y;
	this->breed_need=8;
	this->type='X';	
}
void doodlebugs::move(int target){
	//doodlebug eat ant
	for (int i=0;i<4;i++)
	{
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

		if ((x>=0 &&x<this->rows&&y>=0&&y<this->cols))
			if (this->old_map()[x*(this->cols)+y]!=Null)
				if (this->old_map()[x*(this->cols)+y]->type=='O')
		{
			//eat this  and break;
			printf("doodlebugs(%d,%d) eat ant(%d,%d)\n",this->x,this->y,x,y );
			critter* losser=this->old_map()[x*(this->cols)+y];
			
			this->old_map()[x*(this->cols)+y]=Null;
			this->move_to(x,y);
			//delete losser;
			this->eat_pass=0;
			return;
		}	
	}
	this->eat_pass++;
	//doodlebug move
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
		this->move_to(x,y);
	}
}
void doodlebugs::breed(){
	//calculate which are avaliable
	int avaliable[4]={0};int total=0;
	for (int i=0;i<4 ;i++ )
	{
		int x=this->x,y=this->y;
		switch (i)
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
	if (total==0)return;
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
		this->new_map()[x*(this->cols)+y]=new doodlebugs(this->map,this->rows,this->cols,x,y);
		printf("doodlebugs (%d,%d) breed doodlebugs(%d,%d) \n",this->x,this->y,x,y );
	}	
	this->survive_time=0;
}
