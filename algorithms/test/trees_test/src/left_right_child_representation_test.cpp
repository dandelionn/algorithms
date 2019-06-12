#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <left_right_child_representation.h>

using ::testing::ContainerEq;
using namespace left_right_child_representation;

TEST(LeftRightChildRepresentation, findRoot)
{
	// Arrange
	auto lines = std::vector<int>{ 1, 2, -1, -1, -1, 6, -1, 8, -1,  //left children
								  3, 5, -1, 4, -1, 7, -1, -1, -1 }; //right children
	auto expected = 0;

	// Act
	auto actual = findRoot(lines);

	//Assert
	EXPECT_EQ(actual, expected);
}

TEST(LeftRightChildRepresentation, countLeafs)
{
	// Arrange
	auto lines = std::vector<int>{ 1, 2, -1, -1, -1, 6, -1, 8, -1,  //left children
								  3, 5, -1, 4, -1, 7, -1, -1, -1 }; //right children

	const auto half_size = lines.size() / 2;
	std::vector<int> left(lines.begin(), lines.begin() + half_size);
	std::vector<int> right(lines.begin() + half_size, lines.end());

	auto expected = 4;

	// Act
	auto root = findRoot(lines);
	auto actual = countLeafs(root, left, right);

	//Assert
	EXPECT_EQ(actual, expected);
}

TEST(LeftRightChildRepresentation, computeTreeHeight)
{
	// Arrange
	auto lines = std::vector<int>{ 1, 2, -1, -1, -1, 6, -1, 8, -1,  //left children
								  3, 5, -1, 4, -1, 7, -1, -1, -1 }; //right children
	const auto half_size = lines.size() / 2;
	std::vector<int> left(lines.begin(), lines.begin() + half_size);
	std::vector<int> right(lines.begin() + half_size, lines.end());

	auto expected = 4;

	// Act
	auto root = findRoot(lines);
	auto actual = computeTreeHeight(root, left, right);

	//Assert
	EXPECT_EQ(actual, expected);
}