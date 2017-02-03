#include <cstdlib>

#include "Stack.hpp"

Stack::Stack() : top(NULL) {  }



Stack::~Stack()
{
    StackNode *cur = top;

    while (cur)
    {
        StackNode *rmv = cur;
        cur = cur->next;
        delete rmv;
    }
}



void Stack::add(Creature* item)
{
    StackNode *node = new StackNode;
    node->item = item;

    node->next = top;

    top = node;
}


Creature* Stack::remove()
{

    if (top == NULL)
        return NULL;

    StackNode *old_top = top;

    top = old_top->next;

    Creature* removed = old_top->item;
    
    // free memory 
    delete old_top;
    old_top = NULL;

    return removed;
}
