#include <iostream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstring>


struct mult_div_values {
    int mult;
    float div;
};

bool is_valid_diminsions(int m,int n);
void start(mult_div_values **table, int rows, int cols);
mult_div_values** create_table (int m, int n);
void set_mult_values (mult_div_values **table, int m, int n);
void set_div_values (mult_div_values **table, int m, int n);
void print_mult_table (mult_div_values **table, int m, int n);
void print_div_table (mult_div_values **table, int m, int n);
void delete_table (mult_div_values **table, int m, int n);

//bool is_valid_diminsions(char* m,char *n)；

//bool is_valid_diminsions(char*, char*);
//mult_div_values** creat_table(int,int);
//void set_mult_values(mult_div_values **,int,int);
//void set_div_values(mult_div_values **,int,int);
//void delete_table(mult_div_values **,int);


