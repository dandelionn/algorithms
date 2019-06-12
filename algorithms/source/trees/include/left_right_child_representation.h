#pragma once

#include <vector>
#include <algorithm>
#include <deque>

namespace left_right_child_representation {
	int findRoot(const std::vector<int>& lines);
	int computeTreeHeight(int node, const std::vector<int>& left, std::vector<int>& right);
	int countLeafs(int node, const std::vector<int>& left, std::vector<int>& right);
}