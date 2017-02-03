#include "space.h"
class space_end:public space
{
	public:
	space_end();
	~space_end(){};
	char* type_name;
	int   type;
bool move_to(player* const p);
};