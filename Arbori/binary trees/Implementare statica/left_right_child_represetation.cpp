#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <deque>

using namespace std;

ifstream f("static_tree.in");

std::vector<int> readFile(const std::string filename);
int findRoot(const std::vector<int>& lines);
int computeTreeHeight(int i, const std::vector<int>& left, std::vector<int>& right);
void printNodeState(const int node, const std::vector<int>& childs);
void printTreeState(const std::vector<int>& left, std::vector<int>& right);

int main()
{
   auto lines = readFile("static_tree.in");
   auto root = findRoot(lines);
   cout<< "root: " << root <<'\n';

   const auto half_size = lines.size() / 2;
   std::vector<int> left(lines.begin(), lines.begin() + half_size);
   std::vector<int> right(lines.begin() + half_size, lines.end());
   
   cout<<"tree height: "<<computeTreeHeight(root, left, right) <<'\n';
   printTreeState(left, right);

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

int findRoot(const std::vector<int>& lines)
{
    std::deque<bool> children(lines.size()/2 + 1, false);

    for(auto x: lines)
    {
        children[x+1] = true;
    }

    auto rootIt = std::find(children.begin(), children.end(), false);
    return std::distance(children.begin(), rootIt) - 1;
}

void printTreeState(const std::vector<int>& left, std::vector<int>& right)
{
   for(auto node=0; node < left.size() ; ++node)
   {  
      std::vector<int> childs;
      childs.push_back(left[node]);
      childs.push_back(right[node]);
      childs.erase(std::remove(childs.begin(), childs.end(), -1), childs.end());

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

int computeTreeHeight(int node, const std::vector<int>& left, std::vector<int>& right)
{
   auto noChild = -1;
   if( node == noChild ) return -1; //-1 because this isn't a node
                                    //so we do not add it to the height
   int leftTreeHeight = computeTreeHeight(left[node], left, right);
   int rightTreeHeight = computeTreeHeight(right[node], left, right);

   return 1 + std::max(leftTreeHeight, rightTreeHeight);
}