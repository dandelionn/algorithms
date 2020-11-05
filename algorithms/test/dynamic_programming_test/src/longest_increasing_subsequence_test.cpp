#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <longest_increasing_subsequence.h>

using ::testing::ContainerEq;

TEST(dynamic_programming, longest_increasing_subsequence)
{
	//Arrange
	auto distanceLimit = 9;
	auto values = { 1, -2, -1, 2, 4, -3, -1, 0 };
	auto expected = { -2, -1, 2, 4 };
	
	//Act
	auto actual = findLongestIncreasingSequence(values);

	//Assert
	EXPECT_THAT(actual, expected);
}
