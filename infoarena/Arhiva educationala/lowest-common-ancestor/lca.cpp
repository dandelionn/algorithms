#include <fstream>
#include <vector>
 
void createEulerRepresentation(const std::vector<std::vector<int>>& tree, int node, int level, std::vector<int>& outNodes, std::vector<int>& outLevels)
{
    outNodes.push_back(node);
    outLevels.push_back(level);
 
    for(auto x : tree[node])
    {
        createEulerRepresentation(tree, x, level + 1, outNodes, outLevels);
 
        outNodes.push_back(node);
        outLevels.push_back(level);
    }
}
 
std::vector<int> getNodePositions(const std::vector<int>& nodes, int n)
{
    std::vector<int> positions(n, 0);
    for(auto i=0U; i < nodes.size(); ++i)
    {
        if(positions[nodes[i]] == 0)
        {
            positions[nodes[i]] = i;
        }
    }
 
    return positions;
}
 
int min(const std::vector<int>& levels, int i, int j)
{
    return levels[i] < levels[j] ? i : j;
}
 
std::vector<std::vector<int>> createSparseTable(const std::vector<int>& levels)
{
    std::vector<std::vector<int>> table(1);
    for(auto i=0U; i < levels.size(); ++i)
    {
        table.front().push_back(i);
    }
 
    for(auto i=1U; i < levels.size();  i <<= 1)
    {
        auto v = std::vector<int>();
        for(auto it = table.back().begin(); it + i < table.back().end(); ++it)
        {
            v.push_back(min(levels, *it, *(it+i)));
        }
        table.push_back(v);
    }
 
    return table;
}
 
std::vector<int> createLg(int n)
{
    std::vector<int> lg(2, 0);
    for(auto i=2; i <= n; ++i)
    {
        lg.push_back(lg[i/2] + 1);
    }
 
    return lg;
}
 
int getMin(const std::vector<std::vector<int>>& table, const std::vector<int>& levels, const std::vector<int>& lg, int x, int y)
{
    auto power = lg[y - x + 1];
    int minIndex = min(levels, table[power][x], table[power][y - (1<<power)+1]);
 
    return minIndex;
}
 
int main()
{
    std::ifstream fin("lca.in");
    std::ofstream fout("lca.out");
 
    auto n=0, m=0, x=0, y=0, root = 1;
    fin>>n>>m;
    std::vector<std::vector<int>> tree(n+1);
 
    for(auto child=2, parent = 0; child <= n; ++child)
    {
        fin>>parent;
        tree[parent].push_back(child);
    }
 
    std::vector<int> nodes;
    std::vector<int> levels;
    createEulerRepresentation(tree, root, 1, nodes, levels);
    auto positions = getNodePositions(nodes, n+1);
 
    auto sparseTable = createSparseTable(levels);
    auto lg = createLg(levels.size());
 
    for(auto i=0; i < m; ++i)
    {
        fin >> x >> y;
        auto rangeStart = std::min(positions[x], positions[y]);
        auto rangeEnd = std::max(positions[x], positions[y]);
        auto minIndex = getMin(sparseTable, levels, lg, rangeStart, rangeEnd);
        fout << nodes[minIndex] << '\n';
    }
 
    return 0;
}