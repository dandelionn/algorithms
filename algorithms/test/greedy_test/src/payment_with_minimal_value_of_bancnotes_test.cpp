#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <payment_with_minimal_value_of_bancnotes.h>
#include <vector>

using ::testing::ContainerEq;


TEST(Greedy, payment_with_minimal_value_of_bancnotes)
{
	//Arrange
	auto sum = 175;
	auto bancnotes = std::vector<int>{50, 10, 5, 1};
	auto expected = std::vector<int>{3, 2, 1};

	//Act	
	auto actual = findMinimalAmountOfBancnotes(bancnotes, sum);

	//Assert
	EXPECT_THAT(actual, expected);
}
