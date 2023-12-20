#pragma once

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "../../file/FileManagement.h"
#include <iostream>
#include "glad/glad.h"
#include "../../GameSettings.h"
#include "../Window.h"

using namespace ImGui;
using namespace std;

class Renderer_OpenGL
{
public:
	Renderer_OpenGL(Window* win);
	void assignVars(float vs[], float vss);
	void render();
	void createShaders();
	void makeVAOandVBO();
	void setup(float vs[], float vss);
	void cleanup();
	void calculateWidthMultiplier();

public:
	GLFWwindow* window;
	FileManager* fmanager;
	float* vertices;
	float vertSize;
	string vertexShaderStr;
	string fragmentShaderStr;
	const char* vertexShaderSource;
	const char* fragmentShaderSource;
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;
	unsigned int VBO, VAO;
	int vertAmount;
	int success;
	char infoLog[512];

private:
	//GLFWframebuffersizefun framebuffer_size_callback(GLFWwindow* window, int width, int height);

private: // imgui settings
	bool rendererEnabled = true;
	bool useImprovedRendering = true;
	float pentagonColor[4] = { 0.9058823529411765f, 0.9058823529411765f, 0.9058823529411765f, 1.0f };
	float bgColor[4] = { 0.1294117647058824f, 0.1294117647058824f, 0.1294117647058824f, 1.0f };
	float zoom = 1.0f;
	float widthMultiplier = 2.0f;
};
