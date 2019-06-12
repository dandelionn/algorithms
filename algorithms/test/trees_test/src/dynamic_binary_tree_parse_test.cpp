#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <dynamic_tree.h>
#include <dynamic_binary_tree_parse.h>

using ::testing::ContainerEq;
using namespace dynamic_tree;
using namespace dynamic_binary_tree_parse;

TEST(DynamicBynaryTreeParse, ParseInorder)
{
	//Arrange
	std::deque<int> deq = { 1, 2, 3, 0, 0, 6, 7, 0, 0, 8, 9, 0, 0, 0, 4, 0, 5, 0, 0 };
	auto expected = { 3, 2, 7, 6, 9, 8, 1, 4, 5 };

	//Act
	auto root = createDynamicBinaryTree(deq);
	auto actual = parse(root.get(), ParseType::Inorder);

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(DynamicBynaryTreeParse, ParsePreorder)
{
	//Arrange
	std::deque<int> deq = { 1, 2, 3, 0, 0, 6, 7, 0, 0, 8, 9, 0, 0, 0, 4, 0, 5, 0, 0 };
	auto expected = { 1, 2, 3, 6, 7, 8, 9, 4, 5 };

	//Act
	auto root = createDynamicBinaryTree(deq);
	auto actual = parse(root.get(), ParseType::Preorder);

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(DynamicBynaryTreeParse, ParsePostorder)
{
	//Arrange
	std::deque<int> deq = { 1, 2, 3, 0, 0, 6, 7, 0, 0, 8, 9, 0, 0, 0, 4, 0, 5, 0, 0 };
	auto expected = { 3, 7, 9, 8, 6, 2, 5, 4, 1 };
	
	//Act
	auto root = createDynamicBinaryTree(deq);
	auto actual = parse(root.get(), ParseType::Postorder);

	//Assert
	EXPECT_THAT(actual, expected);
}