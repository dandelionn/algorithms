#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <binary-search.h>

using ::testing::ContainerEq;

TEST(DivideEtImpera, BinarySearch)
{
	//Arrange
	auto values = std::vector<int>{ 3, 20, 18, 5, 9 };
	auto expected = 2;

	//Act
	auto position = -1;
	auto searchedValue = 18;
	BinarySearch(values, 18, 1, 4, position);

	//Assert
	bool actual = position;
	EXPECT_THAT(actual, expected);
}
