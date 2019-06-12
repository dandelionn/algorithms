#pragma once

#include <memory>

struct Node {
	Node() {}
	Node(int value, int count) :
		value(value), count(count) {}
	int value;
	int count;
	std::unique_ptr<Node> left;
	std::unique_ptr<Node> right;
};

enum ParseType { Inorder, Preorder, Postorder };