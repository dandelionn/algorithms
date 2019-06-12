#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <static_binary_tree_parse.h>

using ::testing::ContainerEq;
using namespace static_binary_tree_parse;

TEST(StaticBynaryTreeParse, ParseInorder)
{
	// Inorder (Left, Root, Right)
	// Arrange
	auto lines = std::vector<int>{1, 2, -1, -1, -1, 6, -1, 8, -1,  //left children
								  3, 5, -1, 4, -1, 7, -1, -1, -1}; //right children
	auto expected = { 2, 1, 6, 5, 8, 7, 0, 3, 4 };

	// Act
	auto actual = parse(lines, ParseType::Inorder);

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(StaticBynaryTreeParse, ParsePreorder)
{
	// Preorder (Root, Left, Right)
	// Arrange
	auto lines = std::vector<int>{ 1, 2, -1, -1, -1, 6, -1, 8, -1,  //left children
								  3, 5, -1, 4, -1, 7, -1, -1, -1 }; //right children
	auto expected = { 0, 1, 2, 5, 6, 7, 8, 3, 4 };

	// Act
	auto actual = parse(lines, ParseType::Preorder);

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(StaticBynaryTreeParse, ParsePostorder)
{
	// Postorder (Left, Right, Root)
	// Arrange
	auto lines = std::vector<int>{ 1, 2, -1, -1, -1, 6, -1, 8, -1,  //left children
								  3, 5, -1, 4, -1, 7, -1, -1, -1 }; //right children
	auto expected = { 2, 6, 8, 7, 5, 1, 4, 3, 0 };

	// Act
	auto actual = parse(lines, ParseType::Postorder);

	//Assert
	EXPECT_THAT(actual, expected);
}
