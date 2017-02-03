#ifndef QUEUE_ITER_HPP
#define QUEUE_ITER_HPP

#include "Queue.hpp"


class QueueIter
{
    private:
        Queue::QueueNode *start_pos;
        Queue::QueueNode *cur_pos;
    public:
        QueueIter(Queue& q) : start_pos(q.front), cur_pos(q.front) {  }


        void print_elements();
};

#endif
