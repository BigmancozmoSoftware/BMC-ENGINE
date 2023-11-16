#include "engine/framework/Game.h"
#include "FMOD/fmod.h"
#include <Windows.h>
#include "PrivateData.h"
#include <vector>

using namespace std;

int main(){
	glfwInit();

	if (IsDebuggerPresent()) {
		SetCurrentDirectory(RESOURCE_DIRECTORY);
	}

	// Check GameSettings.h for game config.
	Game* game = new Game();

	game->audio->setVolume(25);
	game->audio->playSound("./resources/sound/bass.mp3");

	ConsoleUtils::blankLine();

	Color* bgColor = new Color(58, 96, 158);

	// init glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, game->window->width, game->window->height);
#if SETTINGS_ANTIALIASING
	glEnable(GL_MULTISAMPLE);
#endif

	// DEFINITIONS
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
	game->renderer->assignVars(vertices, sizeof(vertices));
	game->renderer->createShaders();

	size_t arraySize = sizeof(vertices) / sizeof(vertices[0]);
	int vertAmount = (int)(arraySize / 3);
	cout << "\namount of verts is " << vertAmount << endl;

	// VBO/VAO
	glGenVertexArrays(1, &game->renderer->VAO);
	glGenBuffers(1, &game->renderer->VBO);

	glBindVertexArray(game->renderer->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, game->renderer->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(game->window->getWindow())) {

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(game->renderer->shaderProgram);

		glBindVertexArray(game->renderer->VAO);
		glDrawArrays(GL_TRIANGLES, 0, vertAmount);

		glBindVertexArray(0);

		game->window->update();
	}
	
	game->~Game();

	return 0;
}
