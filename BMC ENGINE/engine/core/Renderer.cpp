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
