#pragma once
#include "../BMCEngine.h"

class Window
{
public:
	Window(int width, int height, const char* title);
private:
	void loadVidMode();
	GLFWwindow* window;
	GLFWmonitor* monitor;
	const GLFWvidmode* vidMode;
};

