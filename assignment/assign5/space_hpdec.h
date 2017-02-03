#include "space.h"
class space_hpdec:public space
{	public:
	space_hpdec();
	~space_hpdec(){};
	char* type_name;
	int   type;
bool move_to(player* const p);
};