#ifndef __state_facts__
#define __state_facts__

#include <iostream>
#include <fstream>  //*i/o information 
#include <cctype>
#include <algorithm>
#include <cstdlib> 
#include <stdlib.h>     /* atoi */
#include <string>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>

using namespace std;

    struct county {
    string name; //name of county
    int population; //total population of county  
    float avg_income; //avg household income
    float avg_house; //avg household price
    int cities; //number of cities in county
    string *city_name; //name of cities in county d
    }; 
    
    struct state {
    string name; //name of state 
    int population; //total population of state
    int counties; //number of counties in state
    struct county *c; //name of counties  
    };   
 
bool is_valid_arguments(char *info[]); 
state * create_states(int);
void get_state_data(state *);
county * create_counties(state * s,int state_count);
void get_county_data(county *); 
void delete_info(state * , int);
bool is_valid_arguments(char** info);


void sort_lar_pop_state(state *s1, int n);
void sort_a_to_z(state *s1, int n); 
void sort_counties_a_to_z(county *s1, int n);
void sort_lar_pop_state(state *s1, int n);
void sort_county_largest_pop(county *s1, int n);
void sort_state_largest_pop(state *s1, int n);
void sort_counties_pop(county *s1, int n);
void sort_lar_county_pop(county *s1, int n);
void fit_county(state *s1, int n);
using namespace std;

#endif