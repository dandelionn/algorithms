#include "binary_tree_parse.h"

// The lowest element in lines is -1; to prevent undefined behavior
// when using it as an index, I just add +1 to all elements
// and in the findRoot method I extract 1 from the computed root
std::deque<bool> markChildren(std::vector<int> lines)
{   
    std::deque<bool> children(lines.size()/2 + 1, false);

    for(auto x: lines)
    {
        children[x+1] = true;
    }

    return children;
}

int findRoot(const std::vector<int>& lines)
{
    auto children = markChildren(lines);
    auto rootIt = std::find(children.begin(), children.end(), false);
    return std::distance(children.begin(), rootIt) - 1;
}

void parse(
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
        parse(left[node], left, right, out);
        parse(right[node], left, right, out);
    }
}

std::vector<int> parseRSD(const std::vector<int>& lines)
{
    const auto half_size = lines.size() / 2;
    std::vector<int> left(lines.begin(), lines.begin() + half_size);
    std::vector<int> right(lines.begin() + half_size, lines.end());
    std::vector<int> out;

    auto root = findRoot(lines);

    parse(root, left, right, out);

    return out;
}

