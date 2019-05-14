#include "dynamic_binary_tree.h"

void create(std::unique_ptr<Node>& node, std::deque<int>& d)
{
    if(d.empty()) return;

    int val = d.front();
    d.pop_front();
    const bool noChild = val == 0;
    if( noChild ) return;
    
    node = std::make_unique<Node>();
    node->value = val;
 
    create(node->left, d);
    create(node->right, d);
}

std::unique_ptr<Node> createDynamicBinaryTree(std::deque<int>d)
{
    std::unique_ptr<Node> root;
    create(root, d);

    return std::move(root);
}



