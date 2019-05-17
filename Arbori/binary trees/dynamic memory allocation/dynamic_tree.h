#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
#include <memory>
#include <vector>

struct Node{
    int value; 
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};

void create(std::unique_ptr<Node>& node, std::deque<int>& d);
std::unique_ptr<Node> createDynamicBinaryTree(std::deque<int>d);
std::vector<int> extractTreeRepresentation(Node *root);
void saveToFile(const std::string filename, std::vector<int> v);

int computeTreeHeight(Node* node);
int countLeafs(Node* node);
void copyTree(Node* source, Node* dest);
bool equals(Node* nodeA, Node* nodeB);
std::vector<int> extractLevelValues(Node* node, int level);
bool valueExists(Node* node, int value);