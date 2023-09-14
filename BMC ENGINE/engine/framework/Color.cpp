#include "Color.h"

Color::Color(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

Color::Color(int r, int g)
{
	Color(r, g, 0);
}

Color::Color(int r)
{
	Color(r, 0, 0);
}

Color::Color()
{
	Color(0, 0, 0);
}
