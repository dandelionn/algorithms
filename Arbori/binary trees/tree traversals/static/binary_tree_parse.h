#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

enum ParseType{Inorder, Preorder, Postorder};

std::vector<int> parse(const std::vector<int>& lines, ParseType parseType);