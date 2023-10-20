// hi welcome to bmc engine

#include "engine/framework/Game.h"
#include "FMOD/fmod.h"
#include <Windows.h>
#include "PrivateData.h"

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

	GLfloat vertices[] = {
		-0.75f, -0.75f, 0.0f,
		-0.25f, -0.75f, 0.0f,
		-0.25f, 0.25f, 0.0f//,
		//1.0f, 1.0f, 0.0f,
	};

	while (!game->window->shouldClose()) {
		game->renderer->setBackgroundColor(bgColor);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		game->window->update();
	}
	
	game->renderer->cleanup();

	glfwTerminate();

	return 0;
}