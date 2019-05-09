#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <algorithm>

class Heap
{
    public:
        Heap(std::vector<int> v);
        int top();
        int pop();
        bool empty();
        void add(int k);
        std::vector<int> getValues();
    private:
        std::vector<int> v;
        void createHeap();
        void siftUp(std::vector<int>::iterator child);
        void siftDown();
        auto selectChildWithBiggerValue(std::vector<int>::iterator parent) ->  std::vector<int>::iterator;
        auto getChild(int childIndex) ->  std::vector<int>::iterator;
};

inline std::vector<int> HeapSort(std::vector<int> values)
{
    Heap heap(values);
    std::vector<int> v;

    while(!heap.empty())
    {
        v.push_back(heap.pop());
    }

    return v;
}

#endif // HEAP_H_INCLUDED