#pragma once
#include "../../BMCEngine.h"

class KeyboardInput
{
public:
	KeyboardInput(Window* win);
	bool isKeyDown(int keycode);
private:
	GLFWwindow* window;
};

