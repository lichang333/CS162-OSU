#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "queue.h"
#include "stack.h"


int main(){
srand(time(NULL));
Queue q;
q.queue_function();
std::string str;
std::cout << "Enter a string for the Stack: ";
std::cin >> str;
std::cout<< "Result: "<<str<<Stack::get_palindrome(str) << std::endl;
return 0;
}