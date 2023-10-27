#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
	Window(int width, int height, const char* title);
	void update();
	bool shouldClose();
	void close();
	GLFWwindow* getWindow();
private:
	GLFWwindow* window;
};

