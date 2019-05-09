#include "heap.h"
#include <iostream>

Heap::Heap(std::vector<int> values)
{
    v = values;
    createHeap();
}

int Heap::top()
{
    return v.front();
}

std::vector<int> Heap::getValues()
{
    return v;
}

void Heap::siftUp(std::vector<int>::iterator child)
{
    auto parent = v.begin() + (std::distance(v.begin(), child) - 1) / 2;

    if(child!=v.begin() && *child > *parent)
    {
        std::swap(*child, *parent);
        siftUp(parent);
    }
}

void Heap::createHeap()
{
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        siftUp(it);
    }
}

auto Heap::getChild(int childIndex) ->  std::vector<int>::iterator
{
    auto child = v.end();

    auto childExists = childIndex < v.size();
    if(childExists)
    {
        child = v.begin() + childIndex;
    }

    return child;
}

auto Heap::selectChildWithBiggerValue(std::vector<int>::iterator parent) ->  std::vector<int>::iterator
{
    auto parentIndex = std::distance(v.begin(), parent) + 1;
    auto firstChild = getChild(parentIndex*2 - 1);
    auto secondChild = getChild(parentIndex*2);
    
    if(secondChild != v.end() && *firstChild < *secondChild)
    {
        firstChild = secondChild;
    }

    return firstChild;
}

void Heap::siftDown()
{
    v.front() = v.back(); 
    v.pop_back();

    auto parent = v.begin();
    auto child = selectChildWithBiggerValue(parent);

    while(child != v.end()  && *parent < *child) 
    {
        std::swap(*parent, *child);
        parent = child;
        child = selectChildWithBiggerValue(parent);
    }
}

int Heap::pop()
{
    auto top = this->top();
    siftDown();

    return top;
}

bool Heap::empty()
{
    return v.empty();
}

void Heap::add(int k)
{
    v.push_back(k);
    siftUp(v.end() - 1);
}

