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

bool MouseInput::leftMouseDown()
{
	return glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
}

bool MouseInput::rightMouseDown()
{
	return glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
}
