#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include "binary_tree_parse.h"

std::vector<int> readFile(std::string filename);
void printMessage(std::string message);

template<class Container>
void printToConsole(const Container& container, std::string message);

int main()
{
    printMessage("STATIC BINARY TREE");

    auto v = readFile("static_tree.in");
    printToConsole(v, "Left+right children vector");

    auto result = parseRSD(v);

    printToConsole(result, "RSD_recursive");

    std::getchar();
}

std::vector<int> readFile(std::string filename) 
{
    std::ifstream fin(filename);
    std::vector<int> lines;

    while(!fin.eof())
    {
        auto x = 0;
        fin>>x;
        lines.push_back(x);
    }

    return lines;
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