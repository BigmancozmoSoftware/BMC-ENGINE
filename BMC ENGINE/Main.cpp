#include "engine/framework/Game.h"
#include "FMOD/fmod.h"
#include <Windows.h>
#include "PrivateData.h"
#include <vector>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

int main(){
	glfwInit();

	if (IsDebuggerPresent()) {
		SetCurrentDirectory(RESOURCE_DIRECTORY);
	}

	// Check GameSettings.h for game config.
	Game* game = new Game();

	game->audio->setVolume(25);
	game->audio->playSound("./resources/sound/bass.mp3");

	cout << "" << endl;

	Color* bgColor = new Color(58, 96, 158);

	// init glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, game->window->width, game->window->height);
	glfwSetFramebufferSizeCallback(game->window->getWindow(), framebuffer_size_callback);

	// DEFINITIONS
	string vertexShaderStr = game->files->ReadFile("./resources/shaders/default/vertexShader.vert");
	string fragmentShaderStr = game->files->ReadFile("./resources/shaders/default/fragmentShader.frag");
	const char* vertexShaderSource = vertexShaderStr.c_str();
	const char* fragmentShaderSource = fragmentShaderStr.c_str();
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;
	unsigned int VBO, VAO;
	int success;
	char infoLog[512];

	// VS/FS
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
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

	float vertices[] = {
		// Triangle 1
		 0.0f, 0.6f, 0.0f,
		 0.35f, 0.0f, 0.0f,
		 -0.35f, 0.0f, 0.0f,

		// Triangle 2
		 -0.35, 0.0f, 0.0f,
		 0.35, 0.0f, 0.0f,
		 -0.2, -0.75f, 0.0f,

		// Triangle 3
		 -0.2, -0.75f, 0.0f,
		 0.35, 0.0f, 0.0f,
		 0.2, -0.75, 0.0f
	};

	size_t arraySize = sizeof(vertices) / sizeof(vertices[0]);
	int vertAmount = (int)(arraySize / 3);
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
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(game->window->getWindow())) {

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, vertAmount);

		glBindVertexArray(0);

		game->window->update();
	}
	
	game->~Game();

	return 0;
}
