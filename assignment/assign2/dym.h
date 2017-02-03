#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <strings.h>
#include "Item.h"
class dym
{
	private:
		int cap;
		int size;

		void resize();
	public:
		item** memory;
		void add(int index,item* input);
		void remove(int index);
		double TotalPrice();
		dym();
		int item_count();
		item* shopping_list(int list_num);
		void print_list();
};
