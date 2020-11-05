#include <vector>

struct tourist {
	int startDay, duration;
	tourist(int startDay, int duration) : startDay(startDay), duration(duration) {}
};

int numberOfScheduledTourists(std::vector<tourist> turists, int nHouses);