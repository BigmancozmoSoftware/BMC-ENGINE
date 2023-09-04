#include "Window.h"

Window::Window(int width, int height, const char* title)
{
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* vidMode = glfwGetVideoMode(monitor);

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, title, NULL, NULL);

	glfwSetWindowPos(window, (vidMode->width / 2) - (width / 2), (vidMode->height / 2) - (height / 2));
	glfwShowWindow(window);

	glfwMakeContextCurrent(window);
}

void Window::update()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}

GLFWwindow* Window::getWindow()
{
	return window;
}
