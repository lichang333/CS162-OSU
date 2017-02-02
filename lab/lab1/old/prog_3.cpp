#include <iostream>
#include <stdlib.h>     /* atoi */
#include "mult_div.h"

using namespace std;

bool is_valid_diminsions(int m,int n);

int main(int arg,char* argv[])
{
//Converts string inputted into int
int rows=atoi(argv[1]);
int cols=atoi(argv[2]);
int choice;

if(is_valid_diminsions(rows,cols)==true){

do{
is_valid_diminsions(rows,cols);
mult_div_values **table;
table =create_table (rows, cols);
set_mult_values(table, rows, cols);
set_div_values(table, rows, cols);
print_mult_table (table, rows, cols);
print_div_table (table, rows, cols);
delete_table(table, rows, cols);
cout << endl;

cout<<"Would you like to see a different size matrix (0-no,1-yes)? ";
cin>>choice;

cout<<"please tell me the rows and cols: \n";
cin>>rows>>cols;  
if(is_valid_diminsions(rows,cols)==false){
    break;
}

}while(choice==1);
}
//system("pause");
/*
if(is_valid_diminsions(rows,cols)==false){
    cout<<"wrong input!\n";
}
*/

else{
    cout<<"invalid value!\n";
do{
    cout<<"please tell me the rows and cols: \n";
    cin>>rows>>cols;  
    if(is_valid_diminsions(rows,cols)==false){
    break;
}
    mult_div_values **table;
    table =create_table (rows, cols);
    set_mult_values(table, rows, cols);
    set_div_values(table, rows, cols);
    print_mult_table (table, rows, cols);
    print_div_table (table, rows, cols);
    delete_table(table, rows, cols);
    cout << endl;

    cout<<"Would you like to see a different size matrix (0-no,1-yes)? ";
    cin>>choice;
}while(choice==1);
}
return 0;
}

bool is_valid_diminsions(int m,int n){
    if(m>0&&n>0){
        return true;
    }else{
        cout<<"wrong input!\n";
        return false;
    }
}