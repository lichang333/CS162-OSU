#include <iostream>

#include "stack_like.hpp"
#include "queue_like.hpp"


using namespace std;




void Menu(){
    bool flag = true;
    stack_like s;
    queue_like q;
    while (flag){
        int choice;
        // int array_count;
        int choice_stack, choice_queue,input_number;

        cout << "1)Stack  2)Queue" << endl;
        cin >> choice;

        switch (choice){
        case 1:
            while(1)
            {
                cout << "1)Push  2)Pop 3) Exit" << endl;
                cin>>choice_stack;
                if(choice_stack==3)
                {
                    return;
                }
                if (choice_stack==1)
                {
                    cout<<"input number:"<<endl;
                    cin>>input_number;
                    s.push(input_number);
                }
                if (choice_stack==2)
                {
                    cout<<"The number is "<<s.pop()<<endl;
                }
            }

            break;
        case 2:
            while(1)
            {
                cout << "1)Push  2)Pop 3) Exit" << endl;
                cin>>choice_queue;
                if(choice_queue==3)
                {
                    return;
                }
                if (choice_queue==1)
                {
                    cout<<"input number:"<<endl;
                    cin>>input_number;
                    q.push(input_number);
                }
                if (choice_queue==2)
                {
                    cout<<"The number is "<<q.pop()<<endl;
                }
            }
            break;
        default:
            break;
        }
    }
}

int main()
{
    Menu();



    return 0;
}
