#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <parent_childtype_representation.h>

using ::testing::ContainerEq;
using namespace parent_childtype_representation;

TEST(ParentChildTypeRepresentation, findRoot)
{
	//Child type: left child = -1, right child = 1

	// Arrange
	auto lines = std::vector<int>{ 1, 2, -1, -1, -1, 6, -1, 8, -1,  //left children
								  3, 5, -1, 4, -1, 7, -1, -1, -1 }; //right children
	const auto half_size = lines.size() / 2;
	std::vector<int> parents(lines.begin(), lines.begin() + half_size);
	std::vector<int> childrenType(lines.begin() + half_size, lines.end());

	auto expected = 2;

	// Act
	auto actual = findRoot(parents);

	//Assert
	EXPECT_EQ(actual, expected);
}

TEST(ParentChildTypeRepresentation, computeTreeHeight)
{
	//Child type: left child = -1, right child = 1

	// Arrange
	auto lines = std::vector<int>{ 1, 2, -1, -1, -1, 6, -1, 8, -1,  //left children
								  3, 5, -1, 4, -1, 7, -1, -1, -1 }; //right children
	const auto half_size = lines.size() / 2;
	std::vector<int> parents(lines.begin(), lines.begin() + half_size);
	std::vector<int> childrenType(lines.begin() + half_size, lines.end());

	auto expected = 2;

	// Act
	auto root = findRoot(parents);
	auto actual = computeTreeHeight(parents, root) - 1;

	//Assert
	EXPECT_EQ(actual, expected);
}
