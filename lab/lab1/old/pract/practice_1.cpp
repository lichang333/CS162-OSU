#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct movies_t{
    string title;
    int year;
}mine,yours;

void printmovie (movies_t movie);

int main(){
    string mystr;
    
    mine.title="Hello,world";
    mine.year=2222;
    
    cout<<"Enter title: ";
    getline(cin,yours.title);
    cout<<"Enter year: ";
    getline(cin,mystr);
    stringstream(mystr)>>yours.year;
    
    cout<<"My favorite is:\n";
    printmovie(mine);
    cout<<"And yours is:\n";
    printmovie(yours);
    

    
    return 0;
}

void printmovie(movies_t movie){
    cout<<movie.title;
    cout<<"("<<movie.year<<")\n";
}