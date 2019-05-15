#include "binary_tree_parse.h"

// The lowest element in lines is -1; to prevent undefined behavior
// when using it as an index, I just add +1 to all elements
// and in the end I extract 1 from the computed root
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

// Left, Root, Right
void parseInorder(
    int node, 
    const std::vector<int>& left, 
    const std::vector<int>& right,
    std::vector<int>& out
    )
{
    auto noChild = -1;
    if(node != noChild)
    {
        parseInorder(left[node], left, right, out);
        out.push_back(node);
        parseInorder(right[node], left, right, out);
    }
}

// Root, Left, Right
void parsePreorder(
    int node, 
    const std::vector<int>& left, 
    const std::vector<int>& right,
    std::vector<int>& out
    )
{
    auto noChild = -1;
    if(node != noChild)
    {
        out.push_back(node);
        parsePreorder(left[node], left, right, out);
        parsePreorder(right[node], left, right, out);
    }
}

// Left, Right, Root
void parsePostorder(
    int node, 
    const std::vector<int>& left, 
    const std::vector<int>& right,
    std::vector<int>& out
    )
{
    auto noChild = -1;
    if(node != noChild)
    {
        parsePostorder(left[node], left, right, out);
        parsePostorder(right[node], left, right, out);
        out.push_back(node);
    }
}

std::vector<int> parse(const std::vector<int>& lines, ParseType parseType)
{
    const auto half_size = lines.size() / 2;
    std::vector<int> left(lines.begin(), lines.begin() + half_size);
    std::vector<int> right(lines.begin() + half_size, lines.end());
    std::vector<int> out;

    auto root = findRoot(lines);

    switch (parseType){
        case ParseType::Inorder:
            parseInorder(root, left, right, out);
            break;

        case ParseType::Preorder:
            parsePreorder(root, left, right, out);
            break;

        case ParseType::Postorder:
            parsePostorder(root, left, right, out);
            break;
    }
    
    return out;
}