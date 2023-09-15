#pragma once
#include "../BMCEngine.h"

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

