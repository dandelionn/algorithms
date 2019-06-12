#include <parent_childtype_representation.h>

namespace parent_childtype_representation {
	int findRoot(const std::vector<int>& parents)
	{
		auto noParent = -1;
		auto rootIt = std::find(parents.begin(), parents.end(), noParent);
		return std::distance(parents.begin(), rootIt);
	}

	int computeTreeHeight(const std::vector<int>& parents, const int parent)
	{
		auto childs = getChilds(parents, parent);

		int maxHeight = 0;
		for (auto x : childs)
		{
			auto height = computeTreeHeight(parents, x);
			maxHeight = std::max(height, maxHeight);
		}

		return 1 + maxHeight;
	}

	std::vector<int> getChilds(const std::vector<int>& parents, const int parent)
	{
		std::vector<int> childs;
		for (auto it = parents.begin(); it != parents.end(); ++it)
		{
			if (*it == parent)
			{
				auto index = std::distance(parents.begin(), it);
				childs.push_back(index);
			}
		}

		return childs;
	}
}