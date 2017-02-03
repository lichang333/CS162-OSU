#include <string>

using namespace std;

class item
{
private:
	string item_name;
	string unit_name;
	int quantity;
	double unit_price;
	double sub_total; //extended price ＝ unit price * quantity on hand . which means subtotal.

public:
	item();
	item(string, string, double, double);

	string getName();
	string getUnitName();
	int getQuantity();
	double getUnitPrice();
	double getSubTotal();

	void println();
	
};