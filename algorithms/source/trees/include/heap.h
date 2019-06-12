#pragma once

#include <vector>
#include <algorithm>

class Heap
{
    public:
        Heap(const std::vector<int>& v);
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
        auto selectChildWithBiggerValue(const std::vector<int>::iterator& parent) ->  std::vector<int>::iterator;
        auto getChild(int childIndex) ->  std::vector<int>::iterator;
};

inline std::vector<int> HeapSort(const std::vector<int>& values)
{
    Heap heap(values);
    std::vector<int> v;

    while(!heap.empty())
    {
        v.push_back(heap.pop());
    }

    return v;
}