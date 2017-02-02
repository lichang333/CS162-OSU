#include <iostream>
#include <stdlib.h>     /* atoi */
#include mult_div.h

int main(int argc, char** argv) {
    
    int rows,cols;
    
    rows=atoi(argv[1]);cols=atoi(argv[2]);
    
    if(rows>0 && cols>0){
        std::cout<<rows<<"\n";
        std::cout<<cols<<"\n";
        int choice;
        
        do{
            std::cout<<"Would you like to see a different size matrix (0-no,1-yes)? ";
            
            std::cin>>choice;
            //询问参数并重新打印阵列
            if(choice==1){
                std::cout<<"play again!\n";
            }
        }while(choice==1);
        
        //        else{std::cout<<"invalid input!\n";}
        
    }
    return 0;
}
    
    
    
