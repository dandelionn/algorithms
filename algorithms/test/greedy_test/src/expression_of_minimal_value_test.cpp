#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <maximum_subset_sum.h>
#include <expression_of_minimal_value.h>
#include <vector>

using ::testing::ContainerEq;

TEST(Greedy, maximum_subset_sum)
{
	//Arrange
	auto valuesA = { -2, -1, -2, 3, 4, 5 };
	auto valuesB = { -5, -4, -1, -1, -2, -5, -7, -8 };
	auto expected = 20;

	//Act	
	auto actual = computeExpressionOfMinimalValue(valuesA, valuesB);

	//Assert
	EXPECT_THAT(actual, expected);
}