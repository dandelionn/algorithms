#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <the_most_valuable_charge.h>
#include <vector>
#include <activities_scheduling.h>

using ::testing::ContainerEq;


TEST(Greedy, activities_scheduling)
{
	//Arrange
	auto expected = { 6, 7, 4, 5, 1 };
	auto activities = std::vector<activity>{ 
							activity(9, 2, 0),
							activity(12, 1, 1),
							activity(8, 2, 2),
							activity(10, 2, 3),
							activity(16, 2, 4),
							activity(14, 2, 5),
							activity(20, 2, 6),
							activity(19, 2, 7) 
						};
	//Act	
	auto actual = scheduleActivities(activities);

	//Assert
	EXPECT_THAT(actual, expected);
}
