#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "header.h"

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file;
	ofstream myfile;
	int n[26];
	for(int i = 0; i < 26; i++){
		n[i] = 0;
	}
	if(argc == 2)
	{
		file.open(argv[1]);
		if(!(file.fail()))
		{
			count_letters(file, n);
			file.close();
			myfile.open("result.txt");
			output_letters(myfile, n);
			myfile.close();
		}

	}
	return 0;
}
