#ifndef __ant_h__
#define __ant_h__ 1

#include "critter.h"
class ants:public critter{
public:
	ants(critter*** map, int rows,int cols, int x,int y);
	void move(int target);
	void breed();
	//int	breed_need=3;
	//char type='O';
};
#endif