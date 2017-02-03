#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "critter.h"
#include "ants.h"
#include "doodlebugs.h"

using namespace std;

int main(int argc, char* argv[]){
	srand(123456);
	critter* map_initer=new critter();
	int row,col,steps,ants_num,doodle__bugs;

	cout<<"[Extra credit]input row, col, steps, ants, doodlebugs.\n";
	
	cin>>row>>col>>steps>>ants_num>>doodle__bugs;

	int ant_count=0;
	int doodlebug_count=0;
	critter*** map=map_initer->init_map(row,col);
	for (int i = 0; i < row*col; ++i)
	{
		int r=rand()%(row*col/(ants_num+15));
		if ((r==0)&&(ant_count<ants_num))
		{	
			ant_count++;
			//set ant
			map_initer->old_map()[i]=new ants(map,row,col,i/col,i%col);
			printf("generate ant@%d,%d\n",i/col,i%col );
			
		}
		else
		{
			r=rand()%(row*col/7);
			if (r==0&&doodlebug_count<doodle__bugs)
			{
				printf("generate doodlebug@%d,%d\n",i/col,i%col );
				//set doodlebugs
				map_initer->old_map()[i]=new doodlebugs(map,row,col,i/col,i%col);
				doodlebug_count++;//fix for more doodlebug
			}
		}

	}
	for (int i = 0; i < steps; ++i)
	{
		for (int j = 0; j < row*col; ++j)
		{
			if (map_initer->old_map()[j]!=Null)
			{
				map_initer->new_map()[j]=map_initer->old_map()[j];
				map_initer->old_map()[j]->move(rand()%4);
				map_initer->old_map()[j]->swap_map();
			}
		}
		for (int j = 0; j < row*col; ++j)
		{
			if ((map_initer->new_map()[j]!=Null)&&(map_initer->new_map()[j]->type=='X'))
			{
				if (map_initer->new_map()[j]->eat_pass>3)	
					map_initer->new_map()[j]=Null;
			}
		}		
		for(int j=0;j<row*col;j++)
		{
			if (map_initer->old_map()[j]!=Null)
				printf("%c ",map_initer->old_map()[j]->type);
			else
				printf("E ");
			if (j%20==19)
				printf("\n");
		}
		int a0;
		
		printf("*********step %d*****************\n",i);
		printf("Press enter to continue.\n");
		cin.get();
		map_initer->swap_map();
	}
	return 0;
}