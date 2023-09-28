#include "../Math.h"

double Math::clamp(double min, double max, double num)
{
	if (num > max) {
		return max;
	}
	if (num < min) {
		return min;
	}
	return num;
}
