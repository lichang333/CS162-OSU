#include <iostream>
#include <cstdlib> 
#include <string>
#include <fstream>
using namespace std;
int main()
{
	string str;
    ifstream input;
    
    input.open("text.txt")
  


	int cnt[256]={};
	for(int i=0;i<str.size();i++)
		cnt[(int)str[i]]++;
	for(int i=0;i<256;i++)//输出字符出现次数
	{
		if(cnt[i]!=0)
			cout<<(char)i<<':'<<cnt[i]<<endl;
	}
    input.close();
    return 0;
}