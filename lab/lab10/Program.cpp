#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include "FibonacciR.h"
#include "FibonacciNR.h"
using namespace std;
void Usage(){
   cout<<"Correct Usage:"<<endl;
   cout<<"./Fibonacci [n]"<<endl;
}
int main(int argc, char** args) {
  clock_t t;
   try{
       const char* input; //Note: char by default initializes to '\0'
       if(args[1]!=0)
       {
           cout<<"1st passed arguement: '"<<args[1]<<"'"<<endl;
           input= args[1];
       }
       int n= atoi(input);
       cout<<"Finding '"<<n<<"'th "<<"fibonacci number...."<<endl;
       cout<<"Calling Recursive Fibonacci implementation"<<endl;

       t = clock();

       FibonacciR fr(n);
       fr.PrintFibonacci();

         t = clock() - t;
         printf ("It took me %lu clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
       

       cout<<"Calling Non-Recursive Fibonacci implementation"<<endl;
          t = clock();
       FibonacciNR fnr(n);

       fnr.PrintFibonacci();
        t = clock() - t;
        printf ("It took me %lu clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
       cout << "Done!!!!" << endl;
       return 0;
   }
   catch(...)
   {
       cout<<"Oops an error occured! Please check usage"<<endl;
       Usage();
    return 1;
   }
}