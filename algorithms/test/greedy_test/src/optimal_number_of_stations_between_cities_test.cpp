#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <optimal_number_of_stations_between_cities.h>
#include <vector>

using ::testing::ContainerEq;


TEST(Greedy, optimal_number_of_stations_between_cities)
{
	//Arrange
	auto distanceLimit = 9;
	auto stations = { 1, 2, 6, 2, 1 };
	auto expected = { 2 };

	//Act
	auto actual = selectStations(stations, distanceLimit);

	//Assert
	EXPECT_THAT(actual, expected);
}
