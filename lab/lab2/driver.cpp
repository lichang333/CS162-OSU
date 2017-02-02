#include "header.h"
#include <cctype>
#include <algorithm>

int main(){
    
    fstream file;
    string input;
    file.open("text.txt");
    
    while(!file.fail()){
    getline(file,input);
    }
    transform(input.begin(),input.end(),input.begin(), ::tolower);
        
    int cnt[256]={};

    
//count_letters() 
count_letters(input,cnt);

/*   
	for(int i=0;i<input.size();i++)
		cnt[(int)input[i]]++;
*/   

     
//output_letters()   

output_letters(cnt);
/*  
	for(int i=0;i<256;i++)
	{
		if(cnt[i]!=0)
			cout<<(char)i<<':'<<cnt[i]<<endl;
	}

*/

  
    file.close();
    cout<<"\n"<<endl;;
    return 0;
    
}