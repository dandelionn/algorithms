#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include "custom_type.h"
#include <deque>

std::unique_ptr<Node> createDynamicBinaryTree(std::deque<int> v);

