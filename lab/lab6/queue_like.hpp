#ifndef __Queue_Like___
#define __Queue_Like___


class queue_like
{
    private:
        struct QueueNode
        {
            public:
                int item;
                // node that will come off queue before this one, or NULL
                QueueNode *previous;
                // node that will come of queue after this one, or NULL
                QueueNode *next;
        };
        
        QueueNode *front;
        QueueNode *back;
        
    public:
        queue_like();
        ~queue_like();
        void push(const int item);
        int pop();
};

#endif
