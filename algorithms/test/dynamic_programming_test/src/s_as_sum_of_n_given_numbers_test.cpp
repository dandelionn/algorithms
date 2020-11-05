#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <s_as_sum_of_n_given_numbers.h>
#include <vector>

using ::testing::ContainerEq;

TEST(dynamic_programming, s_as_sum_of_n_given_numbers)
{
	//Arrange
	auto sum = 10;
	auto numbers = { 2, 2, 3, 5, 6 };
	auto expected = { 5, 5 };
		
	//Act
	auto actual = findNumbers(numbers, sum);
		
	//Assert
	EXPECT_THAT(actual, expected);
}
