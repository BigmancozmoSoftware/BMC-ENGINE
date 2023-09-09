#include "MouseInput.h"

MouseInput::MouseInput(GLFWwindow* window)
{
	this->window = window;
}

int MouseInput::getMouseX()
{
	double x;
	double y;
	glfwGetCursorPos(window, &x, &y);
	return x;
}

int MouseInput::getMouseY()
{
	double x;
	double y;
	glfwGetCursorPos(window, &x, &y);
	return y;
}

int MouseInput::getMouseX(bool relative)
{
	return 0;
}

int MouseInput::getMouseY(bool relative)
{
	return 0;
}
