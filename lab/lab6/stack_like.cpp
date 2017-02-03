#include <limits>
#include <cstdlib>
#include <stdio.h>
#include "stack_like.hpp"

stack_like::stack_like() : top(NULL) {  }

stack_like::~stack_like()
{

    StackNode *cur = top;

    while (cur)
    {
        StackNode *rmv = cur;
        cur = cur->next;
        delete rmv;
    }

    top=NULL;
}



void stack_like::push(const int item)
{
    StackNode *node = new StackNode;
    node->item = item;
    node->next = top;
    top = node;
}


int stack_like::pop()
{
    // if there are no nodes, return -65535 and print error message.
    if (top == NULL){
    	printf("[ Error ] Pop from empty stack!\n");
        return -65535;
    }

    // current value on the top
    StackNode *old_top = top;

    // old value goes down
    top = old_top->next;

    // new value pop first
    int removed = old_top->item;

    // free memory
    delete old_top;
    old_top = NULL;

    return removed;
}
