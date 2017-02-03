#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>


using namespace std;

char get_choice (char input);
void oppdisplay(char* str,int i);
int sum(int *a,int n);
int triangular_num (int n);



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
 	char input_string[255];
 	int num_array[] = {1,2,3,4};
 	int TN;
	
	cout<< "(1) Reverse a string."<<endl;
	cout<< "(2) Calculate the sum of the array."<<endl;
	cout<< "(3) Calculate the triangular number."<<endl;
	cout<< "(q) Quit the program."<<endl;

	input = cin.get();	
	cin.ignore(1,'\n');
	

	switch(input)
	{
		case '1' : cout<<"Input: "<<endl;
		scanf("%s",input_string);
		cin.ignore(100,'\n');
		printf("\nOutput: \n");
		oppdisplay(input_string,0);
		printf("\n\n");
		break;

		case '2' : 
 		printf("Input 5 number with space to seperate: \n");
 		
 		for(int i = 0; i < 5; i++)
 		{
    		cin >> num_array[i];
		}
		cin.ignore(100,'\n');
 		cout<<"Output: "<<sum(num_array,5)<<endl;
		break;

		case '3':
		cout<<"Input triangular number for N:"<<endl;
		cin >> TN;
		cin.ignore(100,'\n');
		cout<<"Output: "<<triangular_num(TN)<<endl;
		break;

		case 'q' : cout << "Quited."<<endl;
			return 'q';

		default : cout << "invalid input" << endl;
   }
}

void oppdisplay(char* str,int i)
{
	if ((str[i])=='\0')
		return;
	oppdisplay(str,i+1);
	cout<<str[i];    
}  

int sum(int *a,int n)
{
	return n==0?0:sum(a,n-1)+a[n-1];
}


int triangular_num (int n)
{
	if (n == 1) 
	 	return  1;
	else if (n == 0) 
		return 0;
	else
		return  triangular_num(n-1) + n;
}
