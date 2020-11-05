#include <vector>

struct activity {
	int hour, duration, id;
	activity(int hour, int duration, int id) : hour(hour), duration(duration), id(id) {}
};

std::vector<int> scheduleActivities(std::vector<activity>& activities);