#ifndef __Stack_Like___
#define __Stack_Like___

class stack_like
{
    private:
        struct StackNode
        {
            public:
                int item;
                StackNode *next;
        };
        StackNode *top;
    public:
        stack_like();
        ~stack_like();
        void push(const int item);
        int pop();
};




#endif
