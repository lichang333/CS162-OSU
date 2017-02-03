//#include <iostream>
#include <cmath>
#include "readMatrix.hpp"
#include "determinant.hpp"

using namespace std;

int main (){
	
	int result;
	int array[3][3]={0};
	int choice=0;
	cout<<"Please type number 2 or 3:\n 2 stands for 2X2\n 3 stands for 3X3\n\nnow type:"<<endl;
	cin>>choice;
	readMatrix(array,choice);
	result=determinant(array,choice);
	
	cout<<"the determinant is : "<<result<<endl;

return 0;	
}

