#pragma once
#include "GLFW/glfw3.h"

class KeyboardInput
{
public:
	KeyboardInput(GLFWwindow* window);
	bool isKeyDown(int keycode);
private:
	GLFWwindow* myWindow;
};

