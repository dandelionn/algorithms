#include <algorithm>
#include <vector>
#include <minimal_waiting_time_for_patients.h>

void schedulePatients(std::vector<patient>& patients)
{
	std::sort(patients.begin(), patients.end(), [](auto x, auto y) -> bool {
		return x.time > y.time;
	});
}