#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <memory>
#include <deque>
#include <string>
#include "tree_traversal.h"

std::vector<std::vector<int>> readFile(std::string filename);
template<class Container>
void printToConsole(const Container& container, std::string message);
void printMessage(std::string message);
void printTree(const std::vector<std::vector<int>>& tree);

template<class Container>
void printValues(const Container& container);
void printLine(std::string message);


int main()
{
    printMessage("ROOTED TREE");
    auto tree = readFile("rooted_tree.in");
    printTree(tree);

    auto root = 0;
    auto result = BreadthFirst(tree, root);
    printToConsole(result, "Breadth first traversal:");

    result = DepthFirst(tree, root);
    printToConsole(result, "Depth first traversal:");
    
    result = DepthFirst_iterative(tree, root);
    printToConsole(result, "Depth first iterative");

    std::getchar();
}

std::vector<std::vector<int>> readFile(std::string filename) 
{
    auto n = 0;
    std::ifstream fin(filename);
    fin>>n;
    std::vector<std::vector<int>> tree(n);

    while(!fin.eof())
    {
        auto x = 0, y = 0;
        fin >> x >> y;
        tree[x].push_back(y);
    }

    return tree;
}

void printTree(const std::vector<std::vector<int>>& tree)
{
    for(auto it=tree.begin(); it != tree.end(); ++it)
    {
        auto node = std::distance(tree.begin(), it);
        printLine("node " + std::to_string(node) + " childs");
        printValues(*it);
    }
}

template<class Container>
void printValues(const Container& container)
{
    std::cout << '\n';
    for(auto value : container)
    {
        std::cout << value << ' ';
    }
}

void printLine(std::string message)
{
    std::cout << '\n' << message;
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