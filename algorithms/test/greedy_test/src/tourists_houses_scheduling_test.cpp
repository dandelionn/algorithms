#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <tourists_houses_scheduling.h>
#include <vector>

using ::testing::ContainerEq;


TEST(Greedy, tourists_houses_scheduling)
{
	//Arrange
	auto nHouses = 3;
	auto tourists = std::vector<tourist>{tourist(10, 3), tourist(1, 0), tourist(2, 0), 
										 tourist(3, 1), tourist(5, 1), tourist(5, 1), 
										 tourist(3, 1), tourist(6, 23), tourist(4, 5), 
										 tourist(8, 7), tourist(2, 0)};
	auto expected = 3;
	
	//Act	
	auto actual = numberOfScheduledTourists(tourists, nHouses);

	//Assert
	EXPECT_THAT(actual, expected);
}