#include "heap.h"

Heap::Heap(std::vector<int> v)
{
    this->v = v;
    createHeap();
}

int Heap::top()
{
    return this->v[0];
}

std::vector<int> Heap::getValues()
{
    return this->v;
}

void Heap::createHeap()
{
    for(auto j=2; j < this->v.size(); ++j)
    {
        auto i = j;
        while( i > 1 )
        {
            if( this->v[i] >= this->v[i/2] )
            {
                std::swap(this->v[i], this->v[i/2]);
                i = i/2;
            }
            else
            {
                i = 1;
            }
        }
    }
}