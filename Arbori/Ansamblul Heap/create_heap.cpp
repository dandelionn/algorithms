#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<int> readFile(std::string filename);
std::vector<int> createHeap(std::vector<int> v);
void printHeapToConsole(std::vector<int> v);

int main()
{
    auto heapData = readFile("heap.in");
    auto heap = createHeap(heapData);
    printHeapToConsole(heap);
}

std::vector<int> readFile(std::string filename)
{
    std::ifstream fin(filename);
    std::vector<int> v;
    size_t n;
    int x;
   
    fin >> n;
    v.push_back(0); // redundant value, the first position in
                    // vector won't be used for simplicity
    for (auto i=1; i<=n; ++i)
    {
        fin >> x;
        v.push_back(x);
    }

    return v;
}

std::vector<int> createHeap(std::vector<int> v)
{
    for(auto j=2; j < v.size(); ++j)
    {
        auto i = j;
        while( i > 1 )
        {
            if( v[i] >= v[i/2] )
            {
                std::swap(v[i], v[i/2]);
                i = i/2;
            }
            else
            {
                i = 1;
            }
        }
    }
    return v;
}

void printHeapToConsole(std::vector<int> v)
{
    for(auto i=1; i < v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }
}