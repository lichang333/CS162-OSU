#include "space.h"
class space_wall:public space
{	public:
	space_wall();
	~space_wall(){};
	char* type_name;
	int   type;
	bool move_to(player* const p);
};