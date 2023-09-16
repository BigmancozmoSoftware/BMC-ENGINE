#include "DeltaTime.h"

DeltaTime::DeltaTime()
{
	current = high_resolution_clock::now();
	previous = high_resolution_clock::now();
	deltaTime = 0;
}

void DeltaTime::get()
{
}

void DeltaTime::update()
{
	current = high_resolution_clock::now();
	duration<double, std::milli> time_span = current - previous;
	deltaTime = time_span.count();
}

void DeltaTime::updatePrevious()
{
	previous = high_resolution_clock::now();
}
