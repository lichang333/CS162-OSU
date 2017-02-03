#include "readMatrix.hpp"

int a,b,c,d,e,f,g,h,i;
void readMatrix(int array[][3],int choice){


		if (choice == 2){
			std::cout<<"type 4 number element: "<<std::endl;
			std::cin>>a>>b>>c>>d;
			
			(array)[0][0] = a;
			(array)[0][1] = b;
			(array)[1][0] = c;
			(array)[1][1] = d;

			std::cout<<"input: "<<std::endl;

    		for(int i = 0; i < choice; i++) { 
        		for(int j = 0; j < choice; j++) 
            		std::cout << array[i][j]<<" "; 
        			std::cout << std::endl; 
    		} 
		}
		else if (choice ==3){
			std::cout<<"type 9 number element: "<<std::endl;
			std::cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
			
			(array)[0][0] = a;
			(array)[0][1] = b;
			(array)[0][2] = c;
			(array)[1][0] = d;
			(array)[1][1] = e;
			(array)[1][2] = f;
			(array)[2][0] = g;
			(array)[2][1] = h;
			(array)[2][2] = i;
			
			std::cout<<"input: "<<std::endl;

    		for(int i = 0; i < choice; i++) { 
        		for(int j = 0; j < choice; j++) 
            		std::cout << array[i][j]<<" "; 
        			std::cout << std::endl; 
    		}
    	}
}
