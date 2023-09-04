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
	printf("Loaded OpenGL!");
}
