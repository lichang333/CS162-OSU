#include "header.h"

int count_letters(string input_str,int *cnt_f){
    for(int i=0;i<input_str.size();i++)
    cnt_f[(int)input_str[i]]++;
    return 0;
}


void output_letters(int *cnt_f){
    ofstream myfile;
    ofstream outfile("result.txt");
    myfile.open ("result.txt");
    for(int i=0;i<256;i++)
	{
    if(cnt_f[i]!=0){
    if((((char)i!=' ')&&((char)i!=',')&&((char)i!='.'))){
        
	cout<<(char)i<<':'<<cnt_f[i]<<endl;
    myfile<<(char)i<<':'<<cnt_f[i]<<endl;
    }
	}
}
myfile.close();
}


