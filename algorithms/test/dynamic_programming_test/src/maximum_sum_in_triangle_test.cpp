#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <maximum_sum_in_triangle.h>
#include <vector>

using ::testing::ContainerEq;


TEST(dynamic_programming, maximum_sum_in_triangle)
{
	//Arrange
	auto distanceLimit = 9;
	auto stations = { 1, 2, 6, 2, 1 };
	auto expected = 20;
	auto triangle = std::vector<std::vector<int>>{ {5, 0, 0, 0}, { 4, 2, 0, 0 }, { 5, 4, 3, 0 }, { 4, 6, 2, 5 } };

	//Act
	auto actual = computeMaximumSum(triangle);

	//Assert
	EXPECT_THAT(actual, expected);
}