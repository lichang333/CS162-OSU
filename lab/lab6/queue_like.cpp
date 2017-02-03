#include <limits>
#include <cstdlib>
#include <stdio.h>
#include "queue_like.hpp"

queue_like::queue_like() : front(NULL), back(NULL)
{
}

queue_like::~queue_like()
{
    QueueNode *cur = front;
    // destroy all the QueueNodes until reach to NULL
    while (cur)
    {
        QueueNode *rmv = cur;
        cur = cur->previous;
        delete rmv;
    }
}

void queue_like::push(const int item)
{
    QueueNode *node = new QueueNode;
    node->item = item;
    node->previous = back;
    node->next = NULL;
    back = node;

    if (node->previous == NULL)
        front = node;
    else
        node->previous->next = node;
}

int queue_like::pop()
{
    if (front == NULL)
    {
        printf("[ Error ] Pop from empty stack!\n");
        return -65535;
    }
    QueueNode *old_front = front;
    front = old_front->next;
    if (front != NULL)
        front->previous = NULL;
    else
        back = NULL;
    int removed = old_front->item;
    delete old_front;

    return removed;
}
