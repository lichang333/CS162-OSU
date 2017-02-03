#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>


using namespace std;

char get_choice (char input);


int main ()
{
	char choice;
	char* input_string;

	while (1)
	{
		choice=get_choice (choice);
		if (choice=='q')break;
	}
	
   return 0;
}


char get_choice (char input)
{
	string item_name;
	string unit_name;
	double unit_price;

 	char input_string[255];
	
	cout<< "##########################################"<<endl;
	cout<< "Welcome to the grocery shopping list!"<<endl;
	cout<< "##########################################"<<endl;

	cout<< "(1) Add an item to the shopping list."<<endl;
	cout<< "(2) Delete an item from the shopping list."<<endl;
	cout<< "(3) Print shopping list."<<endl;
	cout<< "(q) Quit the program."<<endl;

	input = cin.get();	
	cin.ignore(1,'\n');
	

	switch(input)
	{
		
		case '1' : 
		cout<<"item Name: "<<endl;
		getline(cin,item_name);
		cout<<"item's unit: "<<endl;
		getline(cin,unit_name);
		cout<<"Price per unit: "<<endl;
		getline(cin,unit_price);
		// editing

		break;

		case '2' : 
		
		cout<<"Input the item No. which you wish to delete."<<ednl;
		//getline(cin,)
 		
 		// editing




		break;

		case '3':
		shopping_list.print_list();
	

		break;

		case 'q' : cout << "Quited."<<endl;
			return 'q';

		default : cout << "invalid input" << endl;
   }
}

