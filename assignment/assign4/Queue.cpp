#include <cstdlib>

#include "Queue.hpp"

Queue::Queue() : front(NULL), back(NULL) {  }

Queue::~Queue()
{

    QueueNode *current = front;

    while (current)
    {
        QueueNode *rmv = current;
        current = current->next;
        delete rmv;
    }
}

void Queue::add(Creature* item)
{ 
    QueueNode *node = new QueueNode;
    node->item = item;
 
    node->next = back;

    node->prev = NULL;

    back = node;

    if (node->next == NULL)
        front = node;

    else
        node->next->prev = node;
    
    node = NULL;
}

// int Queue::display()
// {
//     int out = front->item;

//     if (out == EMPTY)
//         std::cout << "Queue is Empty. ";

//     return out;
// }



Creature* Queue::remove()
{
    if (front == NULL)
        return NULL;

    QueueNode *old_front = front;

    front = old_front->prev;

    if (front != NULL)
        front->next = NULL;

    else
        back = NULL;

    Creature* removed = old_front->item;
    
    delete old_front;
    old_front = NULL;

    return removed;
}