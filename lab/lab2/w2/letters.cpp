#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "header.h"

using namespace std;

void count_letters(ifstream &file, int *n)
{
	char c;
	string intput;
	while (!(file.eof())) {
		file >> c;
		if (!(c == ' ' || c == ',' || c == '.')){
			if (c > 'Z')
				c = c - ('a' - 'A');
			n[c - 'A']++;
		}
	}
}
void output_letters(ofstream &myfile, int *n)
{
	for(int i = 0; i < 26; i++)
	{
		cout << char ('A' + i) << ": " << n[i] << endl;
		myfile << char ('A' + i) << ": " << n[i] << endl;
	}
}
