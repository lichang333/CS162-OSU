#include <iostream>
#include <string>
#include <iomanip>

#include "item.h"

using namespace std;

item::tiem(string item_name, string unit_name, int quantity, double unit_price, double sub_total)
{
	this -> item_name = item_name;
	this -> unit_name = unit_name;
	this -> quantity = quantity;
 	this -> unit_price = unit_price;
  	this -> sub_total = unit_price * (int)quantity; // debuging
}

string item::getName()
{
	return item_name;
}

string item::getUnitName()
{
	return unit_name;
}

int item::getQuantity()
{
	return quantity;
}

double item::getUnitPrice()
{
	return unit_price;
}

double item::getSubTotal()
{
	return sub_total;
}

void item::println()
{
	cout<<"Item name: "<<item_name<<endl;
	
	cout<<"quantity: "<<quantity;
	cout<<" "<<unit_name<<endl;

	cout<<"$"<<unit_price<<" per "<<unit_name<<"."<<endl; //debuging

	cout<<"------------------------------"<<endl;
	cout<<"Sub total: $"<<sub_total<<endl;//debuging

}
