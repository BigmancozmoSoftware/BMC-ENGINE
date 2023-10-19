#include "Renderer.h"

using namespace std;

Renderer::Renderer()
{
	files = new FileManager();
}

void Renderer::init()
{
	gladLoadGL();

	vss = files->ReadFile("./resources/shaders/default/vertexShaderDefault.vert");
	vertexShaderSource = vss.c_str();
	fss = files->ReadFile("./resources/shaders/default/fragmentShaderDefault.vert");
	fragmentShaderSource = fss.c_str();
	
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

void Renderer::draw()
{
	
}

void Renderer::loadShaders()
{
	
}

void Renderer::cleanup()
{
	cout << "cleanup" << endl;
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
}
