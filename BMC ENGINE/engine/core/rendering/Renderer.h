#pragma once
#include "../../framework/Color.h"
#include "../../framework/Math.h"
#include "../file/FileManagement.h"
#include <iostream>
#include "glad/glad.h"

class Renderer
{
public:
	Renderer();
	void init();
	void setBackgroundColor(int r, int g, int b);
	void setBackgroundColor(Color* color);
	void draw();
	void loadShaders();
	void cleanup();
private:
	FileManager* files;
	string vss;
	string fss;
	const char* fragmentShaderSource;
	const char* vertexShaderSource;
	unsigned int vShader;
	unsigned int shaderProgram;
	unsigned int VBO, VAO;
	unsigned int fShader;
};
