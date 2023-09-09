#pragma once
#include "GLFW/glfw3.h"

class MouseInput
{
public:
	MouseInput(GLFWwindow* window);
	int getMouseX();
	int getMouseY();
private:
	GLFWwindow* window;
};
