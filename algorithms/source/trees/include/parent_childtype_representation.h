#pragma once

#include <vector>
#include <algorithm>

namespace parent_childtype_representation {

	//Child type : left child = -1, right child = 1
	int findRoot(const std::vector<int>& parents);
	std::vector<int> getChilds(const std::vector<int>& parents, const int parent);
	int computeTreeHeight(const std::vector<int>& parents, const int parent);
}