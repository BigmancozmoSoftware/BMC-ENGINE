#pragma once

#include <chrono>
#include <sys/timeb.h>
#include <ctime>

using namespace std::chrono;

class DeltaTime
{
public:
	DeltaTime();
	void get();
	void update();
	void updatePrevious();
private:
	double deltaTime;
	high_resolution_clock::time_point current;
	high_resolution_clock::time_point previous;
};

