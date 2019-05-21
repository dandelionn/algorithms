#include "tree_traversal.h"

using IteratorPairStack = std::stack<std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator>>;

std::vector<int> BreadthFirst(const std::vector<std::vector<int>>& tree, int root)
{
    std::vector<int> out;
    std::queue<int> q;

    q.push(root);
    while(!q.empty())
    {
        auto node = q.front();

        q.pop();
        out.push_back(node);

        for(auto x : tree[node])
        {
            q.push(x);
        }

    }

    return out;
}

std::vector<int> DepthFirst_iterative(const std::vector<std::vector<int>>& tree, int root)
{
    std::vector<int> out;
    IteratorPairStack st;

    std::vector<int> v(1, root);
    st.push(std::make_pair(v.cbegin(), v.cend()));

    while(!st.empty())
    {
        auto& pair = st.top();
        if(pair.first != pair.second)
        {
            auto node = *pair.first;
            ++pair.first;

            out.push_back(node); 
            auto beginIt = tree[node].cbegin();
            auto endIt = tree[node].cend();
            st.push(std::make_pair(beginIt, endIt));
        }
        else
        {
            st.pop();
        }
    }

    return out;
}


void DepthFirst(const std::vector<std::vector<int>>& tree, int node, std::vector<int>& out)
{
    for(auto x : tree[node])
    {
        out.push_back(x);
        DepthFirst(tree, x, out);
    }
}

std::vector<int> DepthFirst(const std::vector<std::vector<int>>& tree, int root)
{
    std::vector<int> out;
    out.push_back(root); 
    DepthFirst(tree, root, out);

    return out;
}
