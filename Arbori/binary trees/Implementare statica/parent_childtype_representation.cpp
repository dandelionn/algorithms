#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>

int findRoot(const std::vector<int>& parents);
std::vector<int> getChilds(const std::vector<int>& parents, const int parent);
int computeTreeHeight(const std::vector<int>& parents, const int parent);
void printNodeState(const int parent, const std::vector<int>& childs);
void printTreeState(const std::vector<int>& parents);
std::vector<int> readFile(const std::string filename);

int main()
{
    auto lines = readFile("parent_childtype.in");
    const auto half_size = lines.size() / 2;
    std::vector<int> parents(lines.begin(), lines.begin() + half_size);
    std::vector<int> childrenType(lines.begin() + half_size, lines.end()); 
    //left child -1, right child 1

    auto root = findRoot(parents);
    std::cout<< "root node: " << root << '\n';
    std::cout<< "tree height: " << computeTreeHeight(parents, root) - 1 <<'\n';
    printTreeState(parents);

    std::getchar();
}

std::vector<int> readFile(const std::string filename) 
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

int findRoot(const std::vector<int>& parents)
{
    auto noParent = -1;
    auto rootIt = std::find(parents.begin(), parents.end(), noParent);
    return std::distance(parents.begin(), rootIt);
}

int computeTreeHeight(const std::vector<int>& parents, const int parent)
{
    auto childs = getChilds(parents, parent);

    int maxHeight = 0;
    for(auto x : childs)
    {
        auto height = computeTreeHeight(parents, x);
        maxHeight = std::max(height, maxHeight);
    }

    return 1 + maxHeight;
}

std::vector<int> getChilds(const std::vector<int>& parents, const int parent)
{
    std::vector<int> childs;
    for(auto it = parents.begin(); it != parents.end(); ++it)
    {   
        if(*it == parent)
        {
            auto index = std::distance(parents.begin(), it);
            childs.push_back(index);
        }
    }

    return childs;
}

void printTreeState(const std::vector<int>& parents)
{
    for(auto node=0; node < parents.size(); ++node)
    {   
        auto childs = getChilds(parents, node);
        printNodeState(node, childs);
    }
}

void printNodeState(const int node, const std::vector<int>& childs)
{
   switch(childs.size())
   {
       case 0:
           std::cout << node << " is a leaf node " << '\n';
           break;
       case 1:
           std::cout << node << " has a child node: " << childs.front() << '\n';
           break;
       case 2:
            std::cout << node << " has two child nodes: " 
                      << childs.front() << ',' << childs.back() << '\n';
            break;
   }
}