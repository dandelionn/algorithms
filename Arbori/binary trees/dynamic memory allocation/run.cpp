#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include "dynamic_tree.h"
#include <string>

std::deque<int> readFile(std::string filename);
template<class Container>
void printToConsole(const Container& container, std::string message);
template<class Container>
void printValues(const Container& container);
template<class T>
void printLine(std::string message, T val);

int main()
{
    auto deq = readFile("dynamic_tree.in");
    printToConsole(deq, "Initial tree representation:");
    auto root = createDynamicBinaryTree(deq);
    auto rep = extractTreeRepresentation(root.get());
    printToConsole(rep, "Output tree representation:");
    saveToFile("dynamic_tree.out", rep);

    printLine("Tree height: ", computeTreeHeight(root.get()));
    printLine("Leafs count: ", countLeafs(root.get()));
    
    auto clone = std::make_unique<Node>();
    copyTree(root.get(), clone.get());
    rep = extractTreeRepresentation(clone.get());
    printToConsole(rep, "Output tree clone representation");

    printLine("Are trees equal: ", equals(root.get(), clone.get()));

    auto level = 2;
    auto values = extractLevelValues(root.get(), level);
    printToConsole(values, "Values on level: " + std::to_string(level));

    auto value = 4;
    auto result = valueExists(root.get(), value);
    printLine("Is value: " + std::to_string(value) + " in tree:", result);
            
    std::getchar();
}

std::deque<int> readFile(std::string filename)
{
    std::ifstream fin(filename);
    std::deque<int> v;
    int x;
   
    while(!fin.eof())
    {
        fin >> x;
        v.push_back(x);
    }

    return v;
}

template<class Container>
void printToConsole(const Container& container, std::string message)
{
    std::cout << '\n' <<message <<'\n';

    for(auto value : container)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

template<class Container>
void printValues(const Container& container)
{
    for(auto value : container)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

template<class T>
void printLine(std::string message, T val)
{
    std::cout << '\n' << message << ' ' << val;
}

void printLine(std::string message)
{
    std::cout << '\n' << message;
}