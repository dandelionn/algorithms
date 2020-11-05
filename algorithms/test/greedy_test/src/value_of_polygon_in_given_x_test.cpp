#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <value_of_polygon_in_given_x.h>
#include <vector>

using ::testing::ContainerEq;

TEST(Greedy, value_of_polygon_in_given_x)
{
	//Arrange
	auto coeficients = std::vector<long>{0, 1, 2, 2, 2, 2, 2, 2};
	auto x = 2;
	auto expected = 190;

	//Act	
	auto actual = computePolygon(coeficients, x);

	//Assert
	EXPECT_THAT(actual, expected);
}
