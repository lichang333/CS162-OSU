#include <iostream>
#include <string>
#include "Queue.hpp"
#include "QueueIter.hpp"

int main()
{
    char choice = '0';
    Queue q;

    while (true)
    {
        std::cout << "\nMenu:\n"
                  << "a) Enter a value to be added to the queue. \n"
                  << "b) Display first node (front) value.\n"
                  << "c) Remove first node (front) value.\n"
                  << "d) Display the queue contents.\n"
                  << "x) Exit.\n\n";

        std::cin>>choice;
        switch (choice)
        {
            case 'a':
            {
                int value;
                std::cin>>value;
                q.addBack(value);
                break;
            }
            case 'b':
            {
                
                std::cout<<"The first node (front) is: ";
                std::cout<<q.getFront()<<"\n";
                break;
                                
            }
            case 'c':
            {

                int value = q.removeFront();
                if (value == -1) 
                    std::cout << "Empty queue!\n";
                else
                    std::cout << "Removed " << value << " from queue.\n";
                break;


            }
            case 'd':
            {
                QueueIter qi(q);
                qi.print_elements();
                break;


            }
            case 'x':
            {
                return 0;
            }

            default: std::cout<<"Invalid input! range: 'a' - 'd' and 'x'\n";
        }

    }
}




