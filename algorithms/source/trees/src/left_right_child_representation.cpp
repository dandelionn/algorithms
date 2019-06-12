#include <left_right_child_representation.h>

namespace left_right_child_representation {
	int findRoot(const std::vector<int>& lines)
	{
		std::deque<bool> children(lines.size() / 2 + 1, false);

		for (auto x : lines)
		{
			children[x + 1] = true;
		}

		auto rootIt = std::find(children.begin(), children.end(), false);
		return std::distance(children.begin(), rootIt) - 1;
	}

	int computeTreeHeight(int node, const std::vector<int>& left, std::vector<int>& right)
	{
		auto noChild = -1;
		if (node == noChild) return -1; //-1 because this isn't a node
										 //so we do not add it to the height
		int leftTreeHeight = computeTreeHeight(left[node], left, right);
		int rightTreeHeight = computeTreeHeight(right[node], left, right);

		return 1 + std::max(leftTreeHeight, rightTreeHeight);
	}

	int countLeafs(int node, const std::vector<int>& left, std::vector<int>& right)
	{
		auto noChild = -1;
		if (node == noChild) return 0;

		auto isLeaf = left[node] == right[node];
		if (isLeaf) return 1;

		return countLeafs(left[node], left, right) +
			countLeafs(right[node], left, right);
	}
}