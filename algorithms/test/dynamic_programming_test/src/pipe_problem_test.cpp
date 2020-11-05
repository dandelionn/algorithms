#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <pipe_problem.h>

using ::testing::ContainerEq;

TEST(dynamic_programming, pipe_problem)
{
	//Arrange
	auto pipeLength = 10;
	auto pieces = { 2, 2, 3, 5, 6 };
	auto expected = { 6, 2, 2 };

	//Act
	auto actual = buildPipe(pieces, pipeLength);

	//Assert
	EXPECT_THAT(actual, expected);
}
