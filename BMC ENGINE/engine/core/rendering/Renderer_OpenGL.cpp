#include "Renderer_OpenGL.h"

Renderer_OpenGL::Renderer_OpenGL()
{
	fmanager = new FileManager();
}

void Renderer_OpenGL::assignVars(float vertices[], float vertSize)
{
	// Load files
	vertexShaderStr = fmanager->ReadFile("./resources/shaders/default/vertexShader.vert");
	fragmentShaderStr = fmanager->ReadFile("./resources/shaders/default/fragmentShader.frag");
	vertexShaderSource = vertexShaderStr.c_str();
	fragmentShaderSource = fragmentShaderStr.c_str();

	// VS/FS
	/*vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// Shader program
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Delete shaders, they're in the program
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// Calculate amount of verts
	size_t arraySize = vertSize / sizeof(vertices[0]);
	vertAmount = (int)(arraySize / 3);
	cout << "\namount of verts is " << vertAmount << endl;

	// VBO/VAO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);*/
}

void Renderer_OpenGL::render()
{
	
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
