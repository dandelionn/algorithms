#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <memory>
#include <deque>
#include "binary_tree_parse.h"
#include "dynamic_binary_tree.h"

std::deque<int> readFile(std::string filename);
std::pair<std::vector<int>, std::vector<int>> readFileForStaticBinaryTree(std::string filename);

template<class Container>
void printToConsole(const Container& container, std::string message);
void printMessage(std::string message);

int main()
{
    printMessage("DYNAMIC BINARY TREE");
    auto v = readFile("dynamic_tree.in");
    printToConsole(v, "initial vector");

    auto root = createDynamicBinaryTree(v);

    auto result = parse(root.get(), ParseType::Inorder);
    printToConsole(result, "Inorder (Left, Root, Right)");

    result = parse(root.get(), ParseType::Preorder);
    printToConsole(result, "Preorder (Root, Left, Right)");

    result = parse(root.get(), ParseType::Postorder);
    printToConsole(result, "Postorder (Left, Right, Root)");

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