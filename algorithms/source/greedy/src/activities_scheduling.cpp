#include <vector>
#include <algorithm>
#include <activities_scheduling.h>

void sort(std::vector<activity>& activities)
{
	std::sort(activities.begin(), activities.end(), 
		[](auto x, auto y) -> bool {
			return x.hour + x.duration > y.hour + y.duration;
		});
		
}

std::vector<int> scheduleActivities(std::vector<activity>& activities)
{
	sort(activities);
	std::vector<int> schedule;
	schedule.push_back(activities.front().id);
	for (auto i = 1; i < activities.size(); ++i)
	{
		auto currentId = schedule.back();
		if (activities[i].hour >= activities[currentId].hour + activities[currentId].duration)
		{
			schedule.push_back(activities[i].id);
		}
	}
	return schedule;
}