#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <algorithm>

class Heap
{
    public:
        Heap(std::vector<int> v);
        int top();
        std::vector<int> getValues();
    private:
        std::vector<int> v;
        void createHeap();
};

#endif // HEAP_H_INCLUDED