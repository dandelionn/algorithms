#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <dynamic_tree.h>

using ::testing::ContainerEq;

using namespace dynamic_tree;

TEST(DynamicTree, createDynamicBinaryTree)
{
	//Arrange
	std::deque<int> deq = { 1, 2, 3, 0, 0, 6, 7, 0, 0, 8, 9, 0, 0, 0, 4, 0, 5, 0, 0 };
	auto expected = { 1, 2, 3, 0, 0, 6, 7, 0, 0, 8, 9, 0, 0, 0, 4, 0, 5, 0, 0 };

	//Act
	auto root = createDynamicBinaryTree(deq);
	auto actual = extractTreeRepresentation(root.get());

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(DynamicTree, computeTreeHeight)
{
	//Arrange
	std::deque<int> deq = { 1, 2, 3, 0, 0, 6, 7, 0, 0, 8, 9, 0, 0, 0, 4, 0, 5, 0, 0 };
	auto expected = 4;

	//Act
	auto root = createDynamicBinaryTree(deq);
	auto actual = computeTreeHeight(root.get());

	//Assert
	EXPECT_EQ(actual, expected);
}

TEST(DynamicTree, countLeafs)
{
	//Arrange
	std::deque<int> deq = { 1, 2, 3, 0, 0, 6, 7, 0, 0, 8, 9, 0, 0, 0, 4, 0, 5, 0, 0 };
	auto expected = 4;

	//Act
	auto root = createDynamicBinaryTree(deq);
	auto actual = countLeafs(root.get());

	//Assert
	EXPECT_EQ(actual, expected);
}

TEST(DynamicTree, copyTree)
{
	//Arrange
	std::deque<int> deq = { 1, 2, 3, 0, 0, 6, 7, 0, 0, 8, 9, 0, 0, 0, 4, 0, 5, 0, 0 };
	auto expected = { 1, 2, 3, 0, 0, 6, 7, 0, 0, 8, 9, 0, 0, 0, 4, 0, 5, 0, 0 };

	//Act
	auto root = createDynamicBinaryTree(deq);
	auto clone = std::make_unique<Node>();
	copyTree(root.get(), clone.get());
	auto actual = extractTreeRepresentation(clone.get());
	
	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(DynamicTree, equals)
{
	//Arrange
	std::deque<int> deq = { 1, 2, 3, 0, 0, 6, 7, 0, 0, 8, 9, 0, 0, 0, 4, 0, 5, 0, 0 };
	auto expected = true;

	//Act
	auto root = createDynamicBinaryTree(deq);
	auto clone = std::make_unique<Node>();
	copyTree(root.get(), clone.get());
	auto actual = equals(root.get(), clone.get());

	//Assert
	EXPECT_EQ(actual, expected);
}

TEST(DynamicTree, extractLevelValues)
{
	//Arrange
	std::deque<int> deq = { 1, 2, 3, 0, 0, 6, 7, 0, 0, 8, 9, 0, 0, 0, 4, 0, 5, 0, 0 };
	auto expected = { 3, 6, 5 };
	auto level = 2;

	//Act
	auto root = createDynamicBinaryTree(deq);
	auto actual = extractLevelValues(root.get(), level);

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(DynamicTree, valueExists)
{
	//Arrange
	std::deque<int> deq = { 1, 2, 3, 0, 0, 6, 7, 0, 0, 8, 9, 0, 0, 0, 4, 0, 5, 0, 0 };
	auto expected = true;
	auto value = 4;

	//Act
	auto root = createDynamicBinaryTree(deq);
	auto actual = valueExists(root.get(), value);

	//Assert
	EXPECT_EQ(actual, expected);
}