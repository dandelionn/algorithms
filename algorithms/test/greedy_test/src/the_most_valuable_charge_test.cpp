#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <the_most_valuable_charge.h>
#include <vector>

using ::testing::ContainerEq;


TEST(Greedy, the_most_valuable_charge)
{
	//Arrange
	auto maxWeight = 20.0F;
	auto objectWeights = { 5.0F, 4.0F, 4.0F, 8.0F, 10.0F };
	auto objectCounts = { 10, 20, 10, 10, 22 };
	auto expected = { 1.0F, 1.0F, 0.7F };

	//Act	
	auto actual = selectObjectsQuantities(objectWeights, objectCounts, maxWeight);

	//Assert
	EXPECT_THAT(actual, expected);
}
