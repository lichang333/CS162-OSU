#include "space.h"
class space_start:public space
{	public:
	space_start();
	~space_start(){};
	char* type_name;
	int   type;
bool move_to(player* const p);
};