#pragma once

#include <vector>
#include <stack>
#include <queue>

namespace tree_traversals {
	std::vector<int> BreadthFirst(const std::vector<std::vector<int>>& tree, int root);
	std::vector<int> DepthFirst(const std::vector<std::vector<int>>& tree, int root);
	std::vector<int> DepthFirst_iterative(const std::vector<std::vector<int>>& tree, int root);
}