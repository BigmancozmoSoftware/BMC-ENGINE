#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
	Window(int w, int h, const char* title);
	void update();
	bool shouldClose();
	void close();
	GLFWwindow* getWindow();
	int width;
	int height;
private:
	GLFWwindow* window;
};

