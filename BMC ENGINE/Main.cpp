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
		0.0, 0.6, 0.0,
		0.35, 0.0, 0.0,
		-0.35, 0.0, 0.0,

		// Triangle 2
		-0.35, 0.0f, 0.0,
		0.35, 0.0f, 0.0f,
		-0.2, -0.75, 0.0f,

		// Triangle 3
		-0.2, -0.75, 0.0,
		0.35, 0.0, 0.0,
		0.2, -0.75, 0.0,

		// test
		-1.0, 1.0, 0.0,
		1.0, 1.0, 0.0,
		-1.0, -1.0, 0.0,

		// test
		1.0, -1.0, 0.0,
		1.0, 1.0, 0.0,
		-1.0, -1.0, 0.0
	};

	game->renderer->setup(vertices, sizeof(vertices));

	while (!glfwWindowShouldClose(game->window->getWindow())) {
		game->renderer->render();
		game->window->update();
	}
	
	game->~Game();

	return 0;
}
