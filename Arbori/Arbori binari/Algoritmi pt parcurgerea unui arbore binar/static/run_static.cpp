#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <memory>
#include <deque>
#include "binary_tree_parse.h"
#include "dynamic_binary_tree.h"

std::pair<std::vector<int>, std::vector<int>> readFile(std::string filename);

template<class Container>
void printToConsole(const Container& container, std::string message);

int main()
{
    printMessage("STATIC BINARY TREE");
    auto pair = readFile("static_tree.in");
    printToConsole(pair.first, "initial left vector");
    printToConsole(pair.second, "initial right vector");

    parseRSD();

    std::getchar();
}

std::pair<std::vector<int>, std::vector<int>> readFile(std::string filename)
{
    std::ifstream fin(filename);
    std::vector<int> left;
    std::vector<int> right;
    
    auto n = 0;
    fin>>n;
    for(auto i=0; i<n; ++i)
    {
        fin >> left[i]; 
    }
    for(auto i=0; i<n; ++i)
    {
        fin >> right[i];
    }

    return std::make_pair(left, right);
}

template<class Container>
void printToConsole(const Container& container, std::string message)
{
    std::cout << message <<'\n';

    for(auto value : container)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

void printMessage(std::string message)
{
    std::cout<<'\n'<<message<<'\n';
}