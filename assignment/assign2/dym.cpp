#include "dym.h"
using namespace std;
//information card reader
int dym::item_count()    //debuging
{
	return this->size;
}

item* dym::shopping_list(int list_num)  //debuging
{
	return this->memory[list_num];
}
void dym::print_list()
{
	for(int i = 0; i < this->size;i++)
	{
		cout<<"List "<<i+1<<":"<<endl;
		this->memory[i]->Print(); //debugging
		cout<<"\n"<<endl;
	}
	cout<<"====================================="<<endl;
	cout<<"Total:"<<TotalPrice()<<endl;
}
double dym::TotalPrice()
{
	double total = 0;

	for(int i = 0; i < this->size;i++) //debuging
	{
		total += this->memory[i]->GetTotal();   //total += groceryList.at(i).GetTotal();
	}

	return total;
}
dym::dym(){
	this->cap=10;
	this->size=0;
	this->memory=(item**)malloc(sizeof(item*)*10);
}

void dym::add(int index,item* input)
{
	this->resize();
	for(int i=this->size;i>index;i--)
	{
		this->memory[i]=this->memory[i-1];
	}
	this->memory[index]=input;
	this->size++;
}

void dym::remove(int index)
{
	for(int i=index;i<this->size;i++)
	{
		this->memory[i]=this->memory[i+1];
	}
	this->size--;
}
void dym::resize()
{
	if (this->cap<=this->size)
	{
		cout<<"do the resize!\n";
		item** new_memory=(item**)malloc(sizeof(item*)*2*this->cap);
		for(int i=0;i<this->size;i++)
		{
			new_memory[i]=this->memory[i];
		}
		free(this->memory);
		this->memory=new_memory;
		this->cap=this->cap*2;
	}
}