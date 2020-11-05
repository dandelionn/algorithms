#include <iostream>
#include <fstream>
#include <vector>
#include <optimal_number_of_stations_between_cities.h>

/*	Problem description
	Select the stations between two cities A and B where a car driver should stop.
	If possible the distance to the next station should be less than distanceLimit
	and the number of stops should be minimal.
*/

struct Station {
	int id;
	int distance;
	Station(int id, int distance) : id(id), distance(distance) {}
};

std::vector<Station> createStations(const std::vector<int>& distanceToNextStation)
{
	std::vector<Station> stations;
	for (auto i = 0; i < distanceToNextStation.size(); i++)
	{
		stations.push_back(Station(i, distanceToNextStation[i]));
	}
	return stations;
}

std::vector<int> selectStations(std::vector<int> distanceToNextStation, int distanceLimit)
{
	auto stations = createStations(distanceToNextStation);
	std::vector<int> selectedStations;
	auto sum=0;
	for (auto it = stations.begin(); it != stations.end(); ++it)
	{
		if (sum + it->distance > distanceLimit)
		{
			auto id = sum == 0 ? it->id : (it-1)->id;
			selectedStations.push_back(id);
			sum = it->distance;
		}
		else
		{
			sum += it->distance;
		}
	}

	return selectedStations;
}
