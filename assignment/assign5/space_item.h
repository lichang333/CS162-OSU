#include "space.h"
class space_item:public space
{	public:
	space_item();
	~space_item(){};
	char* type_name;
	int   type;

bool move_to(player* const p);
};