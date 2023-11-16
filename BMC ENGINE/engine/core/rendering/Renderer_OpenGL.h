#pragma once
#include "../file/FileManagement.h"
#include <iostream>
#include "glad/glad.h"

using namespace std;

class Renderer_OpenGL
{
public:
	Renderer_OpenGL();
	void assignVars(float vertices[], float vertSize);
	void render();
	void createShaders();
public:
	FileManager* fmanager;

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

