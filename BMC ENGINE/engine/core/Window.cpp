#include "Window.h"

Window::Window(int width, int height, const char* title)
{
	loadVidMode();
}

void Window::loadVidMode()
{
	monitor = glfwGetPrimaryMonitor();
	vidMode = glfwGetVideoMode(monitor);
}
