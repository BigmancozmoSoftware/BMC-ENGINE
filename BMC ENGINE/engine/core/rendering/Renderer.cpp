#include "Renderer.h"

using namespace std;

float verts[];

Renderer::Renderer()
{
	files = new FileManager();
}

void Renderer::init(GLfloat verts[])
{
	gladLoadGL();
	
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

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

void Renderer::draw(GLfloat verts[])
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);
}

void Renderer::loadShaders()
{
	vss = files->ReadFile("./resources/shaders/default/vertexShaderDefault.vert");
	fss = files->ReadFile("./resources/shaders/default/fragmentShaderDefault.vert");

	gladLoadGL();
	// code from http://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/
	VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	GLint Result = GL_FALSE;
	int InfoLogLength;

	cout << "Compiling vertex shader" << endl;

	const char* VertexSourcePointer = vss.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);

	if (InfoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
	}

	cout << "Compiling fragment shader" << endl;

	const char* FragmentSourcePointer = fss.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);

	if (InfoLogLength > 0) {
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
	}

	cout << "Creating program" << endl;

	ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);

	if (InfoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	glUseProgram(ProgramID);

	cout << "Finished loading shaders!" << endl;
}

void Renderer::cleanup()
{
	cout << "cleanup" << endl;
	glDeleteProgram(ProgramID);
}
