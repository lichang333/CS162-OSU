#include <cstdlib>  
#include <string>   
#include <iostream> 
#include "Queue.hpp"


Queue::Queue()
{  
    
    QueueNode *fst = new QueueNode();
    fst->item = EMPTY;
    fst->next = fst;
    fst->prev = fst;

    front = fst;
    back = fst;
}



Queue::~Queue()
{

    QueueNode *cur;
    back = front->next;

    while (back != front)
    {
        cur = back;
        back = cur->next;
        delete cur;
    }

    delete back;

    front = NULL;
    back = NULL;
    cur = NULL;
}



void Queue::addBack(int item)
{

    QueueNode *after = back->next;


    if (after->item == EMPTY)
    {
        after->item = item;

        return;
    }


    QueueNode *cur = new QueueNode;
    cur->item = item;
    cur->prev = back;
    cur->next = after;

    back->next = cur;
    after->prev = cur;
    back = cur;
}




int Queue::getFront()
{
    int out = front->item;

    if (out == EMPTY)
        std::cout << "Queue is Empty. ";

    return out;
}




int Queue::removeFront()
{
    int value = front->item;

    front->item = EMPTY;

    front = front->next;
    
    return value;
}
