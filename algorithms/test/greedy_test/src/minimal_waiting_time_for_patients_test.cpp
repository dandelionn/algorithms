#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <minimal_waiting_time_for_patients.h>
#include <vector>

using ::testing::ContainerEq;


TEST(Greedy, minimal_waiting_time_for_patients)
{
	//Arrange
	auto patients = std::vector<patient>{patient(7, 0), 
					 patient(2, 1), 
					 patient(5, 2), 
					 patient(3, 3), 
					 patient(1, 4), 
					 patient(6, 5), 
					 patient(3, 6), 
					 patient(5, 7)};
	auto expectedPatientIds = std::vector<int>{ 0, 5, 2, 7, 3, 6, 1, 4 };

	//Act
	schedulePatients(patients);
	auto actual = std::vector<int>();
	for (auto patient : patients)
	{
		actual.push_back(patient.id);
	}

	//Assert
	EXPECT_THAT(actual, expectedPatientIds);
}
