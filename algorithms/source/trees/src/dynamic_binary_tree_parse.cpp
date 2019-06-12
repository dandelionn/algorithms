#include <dynamic_binary_tree_parse.h>

namespace dynamic_binary_tree_parse {
	// Left, Root, Right
	void parseInorder(Node* node, std::vector<int>& out)
	{
		if (node != nullptr)
		{
			parseInorder(node->left.get(), out);
			out.push_back(node->value);
			parseInorder(node->right.get(), out);
		}
	}

	// Root, Left, Right
	void parsePreorder(Node* node, std::vector<int>& out)
	{
		if (node != nullptr)
		{
			out.push_back(node->value);
			parsePreorder(node->left.get(), out);
			parsePreorder(node->right.get(), out);
		}
	}

	// Left, Right, Root
	void parsePostorder(Node* node, std::vector<int>& out)
	{
		if (node != nullptr)
		{
			parsePostorder(node->left.get(), out);
			parsePostorder(node->right.get(), out);
			out.push_back(node->value);
		}
	}

	std::vector<int> parse(Node* node, ParseType parseType)
	{
		std::vector<int> out;

		switch (parseType) {
		case ParseType::Inorder:
			parseInorder(node, out);
			break;

		case ParseType::Preorder:
			parsePreorder(node, out);
			break;

		case ParseType::Postorder:
			parsePostorder(node, out);
			break;
		}

		return out;
	}
}