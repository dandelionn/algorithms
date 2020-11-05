#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <knapsack.h>
#include <vector>

using ::testing::ContainerEq;

TEST(dynamic_programming, knapsack)
{
	//Arrange
	auto maxWeight = 10;
	auto objects = std::vector<object>{ 
					object(2, 20), object(3, 40), 
					object(6, 50), object(4, 45) };
	auto expected = 105;

	//Act
	auto actual = solveKnapsackProblem(objects, maxWeight);

	//Assert
	EXPECT_THAT(actual, expected);
}
