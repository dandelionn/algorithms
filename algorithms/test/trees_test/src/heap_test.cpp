#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <heap.h>

using ::testing::ContainerEq;

TEST(Heap, constructor_createHeap)
{
	//Arrange
	std::vector<int> heapData = { 3, 20, 18, 5, 9, 15, 11, 25, 2, 10 };
	auto expected = { 25, 20, 18, 9, 10, 15, 11, 3, 2, 5 };

	//Act
	Heap heap(heapData);
	auto actual = heap.getValues();

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(Heap, top_maxValue)
{
	//Arrange
	std::vector<int> heapData = { 3, 20, 18, 5, 9, 15, 11, 25, 2, 10 };
	auto expected = 25;

	//Act
	Heap heap(heapData);
	auto actual = heap.top();

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(Heap, pop)
{
	//Arrange
	std::vector<int> heapData = { 3, 20, 18, 5, 9, 15, 11, 25, 2, 10 };
	auto expected = { 20, 10, 18, 9, 5, 15, 11, 3, 2 };

	//Act
	Heap heap(heapData);
	heap.pop();
	auto actual = heap.getValues();

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(Heap, add)
{
	//Arrange
	std::vector<int> heapData = { 3, 20, 18, 5, 9, 15, 11, 25, 2, 10 };
	auto expected = { 1000000, 25, 18, 9, 20, 15, 11, 3, 2, 5, 10 };

	//Act
	Heap heap(heapData);
	heap.add(1000000);
	auto actual = heap.getValues();

	//Assert
	EXPECT_THAT(actual, expected);
}

TEST(Heap, HeapSort)
{
	//Arrange
	std::vector<int> heapData = { 112, 323, 423, 3434, 23, 1 };
	auto expected = { 3434, 423, 323, 112, 23, 1 };

	//Act
	auto actual = HeapSort(heapData);

	//Assert
	EXPECT_THAT(actual, expected);
}