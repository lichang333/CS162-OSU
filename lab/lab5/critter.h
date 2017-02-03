#ifndef __critter_h__
#define __critter_h__ 1
#define Null 0
#include <stdlib.h> 
#include <stdio.h>
class critter{
	public:
		//critter action
		virtual void move(int target){}//0=up 1=left 2=down 3=right
		virtual void breed(){}         //function breed
	//protected:
		//map help functions
		bool check_edge(int x,int y);
		void swap_map();
		critter** old_map();
		critter** new_map();
		void move_to(int x,int y);
		critter*** init_map(int rows,int cols);//return map
		//the global map information
		critter** map[2];
		int active_buffer;
		int rows;		
		int cols;
		//critter information
		int x;
		int y;
		char type;
		int survive_time;
		int breed_need;
		int eat_pass;//use for doodlebugs but add here for use
};
#endif