#include "KeyboardInput.h"

KeyboardInput::KeyboardInput(Window* win)
{
	window = win->getWindow();
}

bool KeyboardInput::isKeyDown(int keycode)
{
	return glfwGetKey(window, keycode) == GLFW_PRESS;
}
