#include "MouseInput.h"

MouseInput::MouseInput(GLFWwindow* window)
{
	this->window = window;
}

int MouseInput::getMouseX()
{
	double x, y;
	glfwGetCursorPos(window, &x, &y);
	return x;
}

int MouseInput::getMouseY()
{
	double x, y;
	glfwGetCursorPos(window, &x, &y);
	return y;
}