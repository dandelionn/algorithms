#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <deque>
#include "custom_type.h"

enum ParseType{Inorder, Preorder, Postorder};

std::vector<int> parse(Node* node, ParseType parseType);

