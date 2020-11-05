
struct patient {
	int time, id;
	patient(int time, int id) : time(time), id(id) {}
};

void schedulePatients(std::vector<patient>& patients);