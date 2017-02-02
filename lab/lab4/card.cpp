#include "card.h"
#include<iostream>
#include<string>

using namespace std;

card::card(){}

void card::set(string str, int n)
{
	suit = str;
	value = n;
}

string card::get_suit()
{
	return suit;
}

int card::get_value()
{
	return value;
}

card::~card()
{
	//cout << "des in card." << endl;
}

void card::display()
{
	cout << suit<<" " << value << endl;
}