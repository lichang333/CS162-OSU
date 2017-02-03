#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <strings.h>

#include "item.h"
#include "iist.h"

list::list()
{

}

void list::addItem(item & item)
{
	groceryList.push_back(item);
}

//information card reader
int list::item_count()    //debuging
{
	return shopping_list.size();
}

item list::shopping_list(int list_num)  //debuging
{
	return shopping_list.at(list_num);
}

//caculate the total price

double list::TotalPrice()
{
	double total = 0;

	for(int i = 0; i < shopping_list.size();i++) //debuging
	{
		total += shopping_list.at(i).TotalPrice();   //total += groceryList.at(i).GetTotal();
	}

	return total;
}

void list::deleteItem(int list_num)
{
	shopping_list.erase(shopping_list.begin() + list_num);
}


void list:: print_list()
{
	for(int i = 0; i < shopping_list.size();i++)
	{
		cout<<"List "<<i+1<<":"<<endl;
		shopping_list.at(i).print(); //debugging
		cout<<"\n"<<endl;
	}
	cout<<"====================================="<<endl;
	cout<<"Total:"<<GetTotal()<<endl;
}





