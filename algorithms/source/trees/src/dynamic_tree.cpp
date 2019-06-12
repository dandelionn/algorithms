#include <dynamic_tree.h>

namespace dynamic_tree {
	void create(std::unique_ptr<Node>& node, std::deque<int>& d)
	{
		if (d.empty()) return;

		int val = d.front();
		d.pop_front();
		const bool noChild = val == 0;
		if (noChild) return;

		node = std::make_unique<Node>();
		node->value = val;

		create(node->left, d);
		create(node->right, d);
	}

	std::unique_ptr<Node> createDynamicBinaryTree(std::deque<int>d)
	{
		std::unique_ptr<Node> root;
		create(root, d);

		return std::move(root);
	}

	void extractTreeRepresentation(Node *node, std::vector<int>& out)
	{
		if (node == nullptr)
		{
			out.push_back(0);
			return;
		}

		out.push_back(node->value);
		extractTreeRepresentation(node->left.get(), out);
		extractTreeRepresentation(node->right.get(), out);
	}

	std::vector<int> extractTreeRepresentation(Node *root)
	{
		std::vector<int> out;
		extractTreeRepresentation(root, out);

		return out;
	}

	int computeTreeHeight(Node* node)
	{
		if (node == nullptr) return -1;
		//-1 because we go down on more level for nullptr

		return 1 + std::max(computeTreeHeight(node->left.get()),
			computeTreeHeight(node->right.get()));
	}

	int countLeafs(Node* node)
	{
		if (node->left == node->right) return 0;

		return computeTreeHeight(node->left.get()) +
			computeTreeHeight(node->right.get());
	}

	void copyNode(Node* source, Node* dest)
	{
		dest->left = source->left == nullptr ? nullptr : std::make_unique<Node>();
		dest->right = source->right == nullptr ? nullptr : std::make_unique<Node>();
		dest->value = source->value;
	}

	void copyTree(Node* source, Node* dest)
	{
		if (source == nullptr) return;

		copyNode(source, dest);

		copyTree(source->left.get(), dest->left.get());
		copyTree(source->right.get(), dest->right.get());
	}

	bool equals(Node* nodeA, Node* nodeB)
	{
		if (nodeA == nullptr || nodeB == nullptr) return nodeA == nodeB;
		if (nodeA->value != nodeB->value) return false;

		return equals(nodeA->left.get(), nodeB->left.get()) &&
			equals(nodeA->right.get(), nodeB->right.get());
	}

	void extractLevelValues(Node* node, std::vector<int> &out, int currentLevel, int level)
	{
		if (node == nullptr) return;

		if (currentLevel == level)
		{
			out.push_back(node->value);
		}

		extractLevelValues(node->left.get(), out, currentLevel + 1, level);
		extractLevelValues(node->right.get(), out, currentLevel + 1, level);
	}

	std::vector<int> extractLevelValues(Node* node, int level)
	{
		std::vector<int> out;
		extractLevelValues(node, out, 0, level);
		return out;
	}

	bool valueExists(Node* node, int value)
	{
		if (node == nullptr) return false;
		if (node->value == value) return true;

		return valueExists(node->left.get(), value) ||
			valueExists(node->right.get(), value);
	}
}