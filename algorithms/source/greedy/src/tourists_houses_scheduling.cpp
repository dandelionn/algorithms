#include <fstream>
#include <iostream>
#include <algorithm>
#include <tourists_houses_scheduling.h>

void sort(std::vector<tourist>& turists)
{
	std::sort(turists.begin(), turists.end(), [](auto x, auto y) -> bool {
		return x.startDay + x.duration > y.startDay + y.duration;
	});
}

int numberOfScheduledTourists(std::vector<tourist> tourists, int nHouses)
{
	sort(tourists);
	auto houseIndex = 1;
	auto nOfBookedTourists = 0;
	auto endDays = std::vector<int>(nHouses, 0);
	for (auto tourist : tourists)
	{
		houseIndex = houseIndex < nHouses ? houseIndex : 0;
		if (tourist.startDay > endDays[houseIndex])
		{
			endDays[houseIndex] = tourist.startDay + tourist.duration;
			++ houseIndex;
			++ nOfBookedTourists;
		}
	}
	return nOfBookedTourists;
}