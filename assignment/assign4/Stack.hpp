#pragma once

#include "Creature.hpp"

class Stack
{
    private:
        struct StackNode
        {
            public:
                Creature* item;
                StackNode *next;
        };

        StackNode *top;

    public:
        Stack();
        ~Stack();
        void add(Creature* item);
        Creature* remove();
};

