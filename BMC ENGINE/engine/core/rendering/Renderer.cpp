#include "Renderer.h"

using namespace std;

Renderer::Renderer()
{
	files = new FileManager();
}

void Renderer::init()
{
	vss = files->ReadFile("./resources/shaders/default/vertexShaderDefault.vert");
	vertexShader = vss.c_str();
	fss = files->ReadFile("./resources/shaders/default/fragmentShaderDefault.vert");
	fragmentShader = fss.c_str();
	
	gladLoadGL();
	cout << "Renderer initialized" << endl;
}

void Renderer::setBackgroundColor(int r, int g, int b)
{
	Math* math = new Math();
	r = math->clamp(0, 255, r);
	g = math->clamp(0, 255, g);
	b = math->clamp(0, 255, b);

	glClearColor(((float)r) / 255, ((float)g) / 255, ((float)b) / 255, 1);
}

void Renderer::setBackgroundColor(Color* color)
{
	Math* math = new Math();
	int r = math->clamp(0, 255, color->r);
	int g = math->clamp(0, 255, color->g);
	int b = math->clamp(0, 255, color->b);

	glClearColor(((float)r) / 255, ((float)g) / 255, ((float)b) / 255, 1);
}

void Renderer::drawBasic()
{
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::setupBasic(float verts[], int vertCount)
{
	cout << "OpenGL SetupBasic" << endl;

	cout << "compiling v" << endl;
	vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vertexShader, NULL);
	glCompileShader(vShader);
	int success;
	char infoLog[512];
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	cout << "compiling f" << endl;
	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &fragmentShader, NULL);
	glCompileShader(fShader);
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vShader);
	glAttachShader(shaderProgram, fShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	glDeleteShader(vShader);
	glDeleteShader(fShader);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*9, verts, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Renderer::cleanup()
{
	cout << "cleanup" << endl;
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
}
