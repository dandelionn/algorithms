#include "binary_tree_parse.h"
#include <iostream>

void parse(Node* node, std::vector<int>& out)
{
    if(node != nullptr)
    {
        out.push_back(node->value);
        parse(node->left.get(), out);
        parse(node->right.get(), out);
    }
}

std::vector<int> parseRSD(Node* node)
{
    std::vector<int> out;
    parse(node, out);

    return out;
}
