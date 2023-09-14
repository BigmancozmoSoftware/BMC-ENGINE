#include "Renderer.h"
#include <iostream>
#include "../BMCEngine.h"

using namespace std;

Renderer::Renderer()
{
}

void Renderer::init()
{
	gladLoadGL();
	cout << "Loaded OpenGL" << endl;
}

void Renderer::setBackgroundColor(int r, int g, int b)
{
	Math* math = new Math();
	r = math->clamp(0, 255, r);
	g = math->clamp(0, 255, g);
	b = math->clamp(0, 255, b);

	glClearColor(((float)r) / 255, ((float)g) / 255, ((float)b) / 255, 1);
}
