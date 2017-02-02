#include <iostream>
#include <stdlib.h>
#include "mult_div.h"
#include <string>

using namespace std;

int main(int arg,char* argv[])
{
    int rows=atoi(argv[1]),cols=atoi(argv[2]);
    mult_div_values **table;
    string choice;
    do{
        if(is_valid_diminsions(rows,cols)==true){
            start(table, rows, cols);
            cout<<"Would you like to see a different size matrix (n,y)? ";
            cin>>choice;
            if(choice=="y"){cout<<"please tell me the rows and cols: \n";cin>>rows>>cols;if(is_valid_diminsions(rows,cols)==false){break;}}
            else{cout << "Wrong input.\n" << endl;}
            if(is_valid_diminsions(rows,cols)==false)break;}
        else{cout<<"Would you like to see a different size matrix (n,y)? ";cin>>choice;
        if(choice=="y"){cout<<"please tell me the rows and cols: \n";cin>>rows>>cols;if(is_valid_diminsions(rows,cols)==false){break;}}}
    }while(choice=="y");
    return 0;
}