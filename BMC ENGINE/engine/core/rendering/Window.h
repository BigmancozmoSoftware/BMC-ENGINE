#pragma once

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>
#define GL_SILENCE_DEPRECATION

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
	//float WtoHmultiplier;
};

