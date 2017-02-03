
#include "queue.h"


int Queue::getNum(double prob){    //random number generator
if((rand() / (double)RAND_MAX) < prob){
return rand() % 100;
}
else{
return -1;
}
}

void Queue::printQueue(std::queue<int> q){     //print Queue
std::cout << "The now Queue is: ";
while(!q.empty()){
std::cout << q.front() << " ";
q.pop();
}
std::cout <<std::endl;
}

void Queue::queue_function(){       //main queue function
double inPercent, outPercent;
std::cout << "Enter the percentage to randomly create a value (eg: 85 representing 85%): ";
std::cin >> inPercent;
inPercent /= 100;
std::cout << "Enter percentage to remove a value(eg: 85 representing 85%): ";
std::cin >> outPercent;
outPercent /= 100;
int num, val;
std::cout << "How many number(s) you want to simulate?";
std::cin >> num;
std::queue<int> q;
for(int i = 0; i < num; ++i){
val = getNum(inPercent);
if(val != -1){
q.push(val);
}
if((rand() / (double)RAND_MAX) < outPercent && !q.empty()){
q.pop();
}
printQueue(q);
}
}

