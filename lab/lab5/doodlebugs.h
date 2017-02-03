#ifndef __doodlebugs_h__
#define __doodlebugs_h__ 1
#include "critter.h"
class doodlebugs:public critter{
public:
	doodlebugs(critter*** map, int rows,int cols, int x,int y);
	void move(int target);
	void breed();	
	
};
#endif