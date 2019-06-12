#include <binary_search_tree.h>

namespace binary_search_tree {

	void insert(std::unique_ptr<Node>& node, int value)
	{
		if (!node)
		{
			node = std::make_unique<Node>(value, 1);
		}
		else if (value < node->value)
		{
			insert(node->left, value);
		}
		else if (value > node->value)
		{
			insert(node->right, value);
		}
		else
		{
			++node->count;
		}
	}

	std::unique_ptr<Node> createTree(std::vector<int> v)
	{
		std::unique_ptr<Node> root;
		for (auto value : v)
		{
			insert(root, value);
		}

		return root;
	}

	std::unique_ptr<Node> createTree_iterative(std::vector<int> v)
	{
		std::unique_ptr<Node> root;
		for (auto value : v)
		{
			insert_iterative(root, value);
		}

		return root;
	}

	bool exists(Node* node, int value)
	{
		if (!node)
		{
			return false;
		}
		else if (value < node->value)
		{
			return exists(node->left.get(), value);
		}
		else if (value > node->value)
		{
			return exists(node->right.get(), value);
		}
		else
		{
			return true;
		}
	}

	int min(Node* node)
	{
		if (!node->left)
		{
			return node->value;
		}

		return min(node->left.get());
	}

	int max(Node* node)
	{
		if (!node->right)
		{
			return node->value;
		}

		return max(node->right.get());
	}

	void updateSubtree(std::unique_ptr<Node>& node)
	{
		if (!(node->left && node->right))
		{
			node = nullptr;
		}
		else
		{
			auto& child = node->right ? node->right : node->left;
			node->value = child->value;
			node->count = child->count;
			updateSubtree(child);
		}
	}

	bool remove(std::unique_ptr<Node>& node, int value)
	{
		if (!node)
		{
			return false;
		}
		else if (value < node->value)
		{
			return remove(node->left, value);
		}
		else if (value > node->value)
		{
			return remove(node->right, value);
		}
		else
		{
			updateSubtree(node);
			return true;
		}
	}

	void insert_iterative(std::unique_ptr<Node>& root, int value)
	{
		if (!root)
		{
			root = std::make_unique<Node>(value, 1);
			return;
		}

		auto current = root.get();
		while (value != current->value)
		{
			auto& next = value < current->value ? current->left : current->right;
			if (!next)
			{
				next = std::make_unique<Node>(value, 0);
			}
			current = next.get();
		}
		++current->count;
	}

	bool exists_iterative(Node* node, int value)
	{
		while (node && value != node->value)
		{
			node = value < node->value ? node->left.get() : node->right.get();
		}

		return node; //converts to bool
	}

	int min_iterative(Node* node)
	{
		while (node->left)
		{
			node = node->left.get();
		}

		return node->value;
	}

	int max_iterative(Node* node)
	{
		while (node->right)
		{
			node = node->right.get();
		}

		return node->value;
	}

	void updateSubtree_iterative(std::unique_ptr<Node>& node)
	{
		if (!(node->left && node->right))
		{
			node = nullptr;
		}

		auto current = node.get();
		while (current)
		{
			auto& child = current->right ? current->right : current->left;
			current->value = child->value;
			current->count = child->count;

			if (!(child->left && child->right))
			{
				child = nullptr;
			}
			current = child.get();
		}
	}

	bool remove_iterative(std::unique_ptr<Node>& root, int value)
	{
		auto result = false;
		auto node = root.get();
		if (node && value == node->value)
		{
			updateSubtree_iterative(root);
			node = nullptr;
			result = true;
		}

		while (node)
		{
			auto& uNode = value < node->value ? node->left : node->right;
			node = uNode.get();

			if (node && value == node->value)
			{
				updateSubtree_iterative(uNode);
				node = nullptr;
				result = true;
			}
		}

		return result;
	}

	void extractTreeRepresentation(Node *node, std::vector<int>& out)
	{
		if (node == nullptr)
		{
			out.push_back(-1); //-1 means no child
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
}