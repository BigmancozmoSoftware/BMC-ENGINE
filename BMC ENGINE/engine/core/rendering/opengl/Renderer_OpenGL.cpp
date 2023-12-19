#include "Renderer_OpenGL.h"

Renderer_OpenGL::Renderer_OpenGL()
{
	fmanager = new FileManager();
}

void Renderer_OpenGL::assignVars(float verts[], float vs)
{
	// Load files
	vertexShaderStr = fmanager->ReadFile("./resources/shaders/default/vertexShader.vert");
	fragmentShaderStr = fmanager->ReadFile("./resources/shaders/default/fragmentShader.frag");
	vertexShaderSource = vertexShaderStr.c_str();
	fragmentShaderSource = fragmentShaderStr.c_str();
	vertices = verts;
	vertSize = vs;
	size_t arraySize = vs / sizeof(vertices[0]);
	vertAmount = (int)(arraySize / 3);
}

void Renderer_OpenGL::render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertAmount);
	glBindVertexArray(0);
}

void Renderer_OpenGL::createShaders()
{
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Renderer_OpenGL::makeVAOandVBO()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertSize, vertices, GL_STATIC_DRAW);
}

void Renderer_OpenGL::setup(float vs[], float vss)
{
	assignVars(vs, vss);
	createShaders();
	makeVAOandVBO();

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
