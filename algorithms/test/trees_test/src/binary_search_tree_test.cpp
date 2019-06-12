#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <binary_search_tree.h>

using ::testing::ContainerEq;
using namespace binary_search_tree;

TEST(BinarySearchTree, exists)
{
	//Arrange
	auto initialTreeRepresentation = { 15, 10, 20, 7, 7, 12, 17, 23, 5, 8, 14, 21, 25, 0 };
	auto value = 7;
	auto expected = true;
	//Act
	auto root = createTree(initialTreeRepresentation);
	auto actual = exists(root.get(), value);

	//Assert
	EXPECT_EQ(actual, expected);
}

TEST(BinarySearchTree, min)
{
	//Arrange
	auto initialTreeRepresentation = { 15, 10, 20, 7, 7, 12, 17, 23, 5, 8, 14, 21, 25};
	auto expected = 5;

	//Act
	auto root = createTree(initialTreeRepresentation);
	auto actual = min(root.get());

	//Assert
	EXPECT_EQ(actual, expected);
}

TEST(BinarySearchTree, max)
{
	//Arrange
	auto initialTreeRepresentation = { 15, 10, 20, 7, 7, 12, 17, 23, 5, 8, 14, 21, 25, 0 };
	auto expected = 25;

	//Act
	auto root = createTree(initialTreeRepresentation);
	auto actual = max(root.get());

	//Assert
	EXPECT_EQ(actual, expected);
}


TEST(BinarySearchTree, remove)
{
	//Arrange
	auto initialTreeRepresentation = { 15, 10, 20, 7, 7, 12, 17, 23, 5, 8, 14, 21, 25, 0 };
	auto value = 7;
	auto expected = { 15, 10, 8, 5, 0, -1, -1, -1, -1, 12, -1, 14, -1, -1, 20, 17, -1, -1, 23, 21, -1, -1, 25, -1, -1 };
	
	//Act
	auto root = createTree(initialTreeRepresentation);
	remove(root, value);
	auto actual = extractTreeRepresentation(root.get());
	
	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(BinarySearchTree, createTree_iterative)
{
	//Arrange
	auto initialTreeRepresentation = { 15, 10, 20, 7, 7, 12, 17, 23, 5, 8, 14, 21, 25, 0 };
	auto value = 7;
	auto expected = { 15, 10, 8, 5, 0, -1, -1, -1, -1, 12, -1, 14, -1, -1, 20, 17, -1, -1, 23, 21, -1, -1, 25, -1, -1 };

	//Act
	auto root = createTree_iterative(initialTreeRepresentation);
	remove(root, value);
	auto actual = extractTreeRepresentation(root.get());

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(BinarySearchTree, exists_iterative)
{
	//Arrange
	auto initialTreeRepresentation = { 15, 10, 20, 7, 7, 12, 17, 23, 5, 8, 14, 21, 25, 0 };
	auto value = 7;
	auto expected = true;
	//Act
	auto root = createTree_iterative(initialTreeRepresentation);
	auto actual = exists_iterative(root.get(), value);

	//Assert
	EXPECT_EQ(actual, expected);
}

TEST(BinarySearchTree, min_iterative)
{
	//Arrange
	auto initialTreeRepresentation = { 15, 10, 20, 7, 7, 12, 17, 23, 5, 8, 14, 21, 25, 0};
	auto expected = 0;

	//Act
	auto root = createTree_iterative(initialTreeRepresentation);
	auto actual = min_iterative(root.get());

	//Assert
	EXPECT_EQ(actual, expected);
}

TEST(BinarySearchTree, max_iterative)
{
	//Arrange
	auto initialTreeRepresentation = { 15, 10, 20, 7, 7, 12, 17, 23, 5, 8, 14, 21, 25, 0 };
	auto expected = 25;

	//Act
	auto root = createTree_iterative(initialTreeRepresentation);
	auto actual = max_iterative(root.get());

	//Assert
	EXPECT_EQ(actual, expected);
}

TEST(BinarySearchTree, remove_iterative)
{
	//Arrange
	auto initialTreeRepresentation = { 15, 10, 20, 7, 7, 12, 17, 23, 5, 8, 14, 21, 25, 0 };
	auto value = 7;
	auto expected = { 15, 10, 8, 5, 0, -1, -1, -1, -1, 12, -1, 14, -1, -1, 20, 17, -1, -1, 23, 21, -1, -1, 25, -1, -1 };

	//Act
	auto root = createTree_iterative(initialTreeRepresentation);
	remove_iterative(root, value);
	auto actual = extractTreeRepresentation(root.get());

	//Assert
	EXPECT_THAT(actual, expected);
}