#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <mergesort.h>

using ::testing::ContainerEq;

TEST(DivideEtImpera, MergeSort)
{
	//Arrange
	auto values = std::vector<int>{ 0, 20, 18, 5, 9 };
	auto expected = std::vector<int>{ 0, 5, 9, 18, 20 };

	//Act
	MergeSort(values, 1, 4);
	auto actual = values;

	//Assert
	EXPECT_THAT(actual, expected);
}
