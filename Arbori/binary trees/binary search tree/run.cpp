#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "binary_search_tree.h"

template<class T>
void printLine(std::string message, T val);
void printLine(std::string message);
std::vector<int> readFile(std::string filename);
template<class Container>
void printToConsole(const Container& container, std::string message);
std::vector<int> extractTreeRepresentation(Node *root);
template<class Container>
void printValues(const Container& container);

int main()
{
    auto v = readFile("tree.in");
    printToConsole(v, "Initial tree representation");

    auto root = createTree(v);
    auto value = 7;
    printLine("Exist value " + std::to_string(value) + " in tree: ", 
                    exists(root.get(), value));

    printLine("Min value in tree:", min(root.get()));
    printLine("Max value in tree:", max(root.get()));
    printLine("Value " + std::to_string(value) + " removed from tree:", 
                remove(root, value));
    
    printLine("Min value in tree:", min(root.get()));
    printLine("Max value in tree:", max(root.get()));
    auto rep = extractTreeRepresentation(root.get());
    printLine("Tree representation after removing node with value", value);
    printValues(rep);

    printLine("");
    root = createTree_iterative(v);
    value = 7;
    printLine("Exist value " + std::to_string(value) + " in tree: ", 
                    exists_iterative(root.get(), value));

    printLine("Min value in tree:", min_iterative(root.get()));
    printLine("Max value in tree:", max_iterative(root.get()));
    printLine("Value " + std::to_string(value) + " removed from tree:", 
                remove_iterative(root, value));
    
    printLine("Min value in tree:", min_iterative(root.get()));
    printLine("Max value in tree:", max_iterative(root.get()));
    rep = extractTreeRepresentation(root.get());
    printLine("Tree representation after removing node with value", value);
    printValues(rep);

    std::getchar();
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

template<class Container>
void printValues(const Container& container)
{
    std::cout << '\n';
    for(auto value : container)
    {
        std::cout << value << ' ';
    }
}


void extractTreeRepresentation(Node *node, std::vector<int>& out)
{
    if(node == nullptr)
    {
        out.push_back(-1); //-1 means no child
        return;
    }

    out.push_back(node->value);
    extractTreeRepresentation(node->left.get(), out);
    extractTreeRepresentation(node->right.get(), out);
}

std::vector<int> extractTreeRepresentation(Node *root)
{
    std::vector<int> out;
    extractTreeRepresentation(root, out);

    return out;
}