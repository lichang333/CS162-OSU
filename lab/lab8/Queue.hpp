#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
    private:
        struct QueueNode
        {
            public:
                int item;
                QueueNode *next;
                QueueNode *prev;
        };
        
        QueueNode *front;
        QueueNode *back;

        static const int EMPTY = -1;
        
    public:
        Queue();
        ~Queue();

        void addBack(int item);
                               
        int getFront();        
        int removeFront();     
        friend class QueueIter;
};

#endif
