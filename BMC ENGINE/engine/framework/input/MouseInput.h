#pragma once
#include "GLFW/glfw3.h"

class MouseInput
{
public:
	MouseInput(GLFWwindow* window);
	int getMouseX();
	int getMouseY();
	int getMouseX(bool relative);
	int getMouseY(bool relative);
private:
	GLFWwindow* window;
};
