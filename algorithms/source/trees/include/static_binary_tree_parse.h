#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <custom_type.h>

namespace static_binary_tree_parse {
	std::vector<int> parse(const std::vector<int>& lines, ParseType parseType);
}