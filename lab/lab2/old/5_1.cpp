#include <iostream>
#include <cstdlib> 
#include <string>
#include <fstream>

using namespace std;

int main(){
    
    fstream file;
    string input;
    file.open("text.txt");
    
    while(!file.fail()){
    getline(file,input);
    }

    int cnt[256]={};
	for(int i=0;i<input.size();i++)
		cnt[(int)input[i]]++;
	for(int i=0;i<256;i++)
	{
		if(cnt[i]!=0)
			cout<<(char)i<<':'<<cnt[i]<<endl;
	}
    
    
    
    file.close();
    cout<<"\n"<<endl;;
    return 0;
    
}