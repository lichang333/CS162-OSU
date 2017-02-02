#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cout<<"input some text:"<<endl;
	getline(cin,str);
	int cnt[256]={};
	for(int i=0;i<str.size();i++)
		cnt[(int)str[i]]++;
	for(int i=0;i<256;i++)//输出字符出现次数
	{
		if(cnt[i]!=0)
			cout<<(char)i<<':'<<cnt[i]<<endl;
	}
}