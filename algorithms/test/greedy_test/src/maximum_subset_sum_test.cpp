#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <maximum_subset_sum.h>
#include <vector>

using ::testing::ContainerEq;


TEST(Greedy, maximum_subset_sum)
{
	//Arrange
	auto values = std::vector<int>{ -1, -4, -3, -5, -6, -8, -8 };
	auto expected = std::vector<int>{-1};

	//Act	
	auto actual = findMaximalSumSubset(values);

	//Assert
	EXPECT_THAT(actual, expected);
}
