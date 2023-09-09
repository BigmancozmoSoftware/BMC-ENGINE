#include "KeyboardInput.h"

KeyboardInput::KeyboardInput(GLFWwindow* window)
{
	myWindow = window;
}

bool KeyboardInput::isKeyDown(int keycode)
{
	return glfwGetKey(myWindow, keycode) == GLFW_PRESS;
}
