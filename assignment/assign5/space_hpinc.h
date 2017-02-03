#include "space.h"
class space_hpinc:public space
{	public:
	space_hpinc();
	~space_hpinc(){};
	char* type_name;
	int   type;
bool move_to(player* const p);
};