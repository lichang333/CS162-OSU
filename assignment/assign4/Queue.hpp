#pragma once

#include "Creature.hpp"


class Queue
{
	private:

        struct QueueNode
        {
            public:
                Creature *item;
                QueueNode *next;
                QueueNode *prev;
        };

    	QueueNode *front;
    	QueueNode *back;

	public:
        
		Queue();
		~Queue();
        void add(Creature* item);
        Creature* remove();


};



