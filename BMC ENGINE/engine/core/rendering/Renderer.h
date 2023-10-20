#pragma once
#include "../../framework/Color.h"
#include "../../framework/Math.h"
#include "../file/FileManagement.h"
#include <iostream>
#include "glad/glad.h"
#include <vector>

class Renderer
{
public:
	Renderer();
	void init(GLfloat verts[]);
	void setBackgroundColor(int r, int g, int b);
	void setBackgroundColor(Color* color);
	void draw(GLfloat verts[]);
	void loadShaders();
	void cleanup();
private:
	FileManager* files;
	string vss;
	string fss;
	GLuint VertexShaderID;
	GLuint FragmentShaderID;
	GLuint ProgramID;
	GLuint vertexBuffer;
	GLuint VertexArrayID;
};
