#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <deque>
#include <custom_type.h>

namespace dynamic_binary_tree_parse {
	std::vector<int> parse(Node* node, ParseType parseType);
}
