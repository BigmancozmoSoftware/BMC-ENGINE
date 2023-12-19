#pragma once

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "../../file/FileManagement.h"
#include <iostream>
#include "glad/glad.h"
#include "../../GameSettings.h"

using namespace ImGui;
using namespace std;

class Renderer_OpenGL
{
public:
	Renderer_OpenGL();
	void assignVars(float vs[], float vss);
	void render();
	void createShaders();
	void makeVAOandVBO();
	void setup(float vs[], float vss);
	void cleanup();
public:
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
};

