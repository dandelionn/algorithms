#pragma once

#include <cstdio>
#include <vector>
#include <memory>
#include <algorithm>
#include <custom_type.h>

namespace binary_search_tree {
	void insert(std::unique_ptr<Node>& node, int value);
	std::unique_ptr<Node> createTree(std::vector<int> v);
	bool exists(Node* node, int value);
	int min(Node* node);
	int max(Node* node);
	bool remove(std::unique_ptr<Node>& node, int value);

	void insert_iterative(std::unique_ptr<Node>& node, int value);
	std::unique_ptr<Node> createTree_iterative(std::vector<int> v);
	bool exists_iterative(Node* node, int value);
	int min_iterative(Node* node);
	int max_iterative(Node* node);
	bool remove_iterative(std::unique_ptr<Node>& node, int value);
	std::vector<int> extractTreeRepresentation(Node *root);
}