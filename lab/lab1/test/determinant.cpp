#include "determinant.hpp"
int result;

int determinant(int array[3][3],int choice){



	if (choice == 2){
		result = array[0][0]*array[1][1]-array[1][0]*array[0][1];	
	}
	else if (choice == 3){
		result = array[0][0] * array[1][1] * array[2][2] + array[0][1] * array[1][2] * array[2][0] + array[0][2] * array[1][0] * array[2][1] - array[0][2] * array[1][1] * array[2][1] - array[0][2] * array[1][1] * array[2][0] - array[0][0] * array[1][2] * array[2][1] - array[0][1] * array[1][0] * array[2][2];	
	}

	return result;
}