#include <iostream>
#include <stdlib.h>     /* atoi */


int main(int argc, char** argv) {
//    std::cout << "Have " << argc << " arguments:" << std::endl;
//    for (int i = 0; i < argc; ++i) {
//        std::cout << argv[i] << std::endl;
//        }

int rows,cols;

rows=atoi(argv[1]);cols=atoi(argv[2]);

if(rows>0 && cols>0){
std::cout<<rows+1<<"\n";
std::cout<<cols+1<<"\n";
}

else{std::cout<<"invalid input!\n";}
}

struct_mult_div_values{
    int mult;
    float div;
}