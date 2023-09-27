#pragma once
#include "../../framework/Color.h"
#include "../../framework/Math.h"
#include <iostream>
#include "glad/glad.h"

class Renderer
{
public:
	Renderer();
	void init();
	void setBackgroundColor(int r, int g, int b);
	void setBackgroundColor(Color* color);
};
