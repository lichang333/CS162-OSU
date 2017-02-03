#include <iostream>

#include "QueueIter.hpp"


void QueueIter::print_elements() {
    std::cout << "Queue contents: \n";

    do
    {
        int cur_val = cur_pos->item;
        if (cur_val != Queue::EMPTY)
            std::cout << cur_pos->item << ' ';
        cur_pos = cur_pos->next;
    }
    while (cur_pos != start_pos);
    std::cout << '\n';
}
