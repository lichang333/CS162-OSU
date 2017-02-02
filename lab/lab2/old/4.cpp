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
    cout<<input;
    }
    
    file.close();
    cout<<"\n"<<endl;;
    return 0;
    
}