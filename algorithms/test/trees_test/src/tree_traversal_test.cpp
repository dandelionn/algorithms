#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <tree_traversal.h>

using ::testing::ContainerEq;
using namespace tree_traversals;

TEST(TreeTraversal, BreadthFirst)
{
	//Arrange
	auto tree = std::vector<std::vector<int>>{ {1, 2}, {3, 4}, {5}, {6, 7, 8}, 
											   {}, {}, {}, {}, {} };
	auto root = 0;
	auto expected = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	//Act
	auto actual = BreadthFirst(tree, root);

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(TreeTraversal, DepthFirst)
{
	//Arrange
	auto tree = std::vector<std::vector<int>>{ {1, 2}, {3, 4}, {5}, {6, 7, 8},
											   {}, {}, {}, {}, {} };
	auto root = 0;
	auto expected = { 0, 1, 3, 6, 7, 8, 4, 2, 5 };

	//Act
	auto actual = DepthFirst(tree, root);

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(TreeTraversal, DepthFirst_iterative)
{
	//Arrange
	auto tree = std::vector<std::vector<int>>{ {1, 2}, {3, 4}, {5}, {6, 7, 8},
											   {}, {}, {}, {}, {} };
	auto root = 0;
	auto expected = { 0, 1, 3, 6, 7, 8, 4, 2, 5 };

	//Act
	auto actual = DepthFirst_iterative(tree, root);
	
	//Assert
	EXPECT_THAT(actual, expected);
}