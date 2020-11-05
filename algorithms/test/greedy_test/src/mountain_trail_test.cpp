#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <mountain_trail.h>
#include <vector>

using ::testing::ContainerEq;


TEST(Greedy, mountain_trail)
{
	//Arrange
	const std::vector<std::vector<int>> points = { {2, 1, 2, 1}, { 0, 0, 4, 2 }, { 0, 0, 4, 2 }, { 3, 1, 2, 3 } };
	const auto startPoint = Point(2, 2);
	auto expected = std::vector<int>{2, 2, 1, 1};

	//Act
	auto selectedPoints = searchTrail(points, startPoint);
	auto actual = std::vector<int>();
	for (auto point : selectedPoints)
	{
		actual.push_back(point.x);
		actual.push_back(point.y);
	}

	//Assert
	EXPECT_THAT(actual, expected);
}