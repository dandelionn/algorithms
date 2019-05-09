#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include "heap.h"

std::vector<int> readFile(std::string filename);
void printHeapToConsole(std::vector<int> v, std::string message);

int main()
{
    auto heapData = readFile("heap.in");

    Heap heap(heapData);
    printHeapToConsole(heap.getValues(), "CREATE");

    std::cout<< "max value:" << heap.pop() <<'\n';
    printHeapToConsole(heap.getValues(), "POP");

    heap.add(1000000);
    printHeapToConsole(heap.getValues(), "ADD");

    auto v = HeapSort({112, 323, 423, 3434, 23, 1});
    printHeapToConsole(v, "HeapSort");

    std::getchar();
}

std::vector<int> readFile(std::string filename)
{
    std::ifstream fin(filename);
    std::vector<int> v;
    int x;
   
    while(!fin.eof())
    {
        fin >> x;
        v.push_back(x);
    }

    return v;
}

void printHeapToConsole(std::vector<int> v, std::string message)
{
    std::cout << message <<'\n';

    for(auto value : v)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}