// hi welcome to bmc engine

#include "engine/BMCEngine.h"
#include "GameSettings.h"
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

	game->audio->setVolume(10);
	game->audio->playSound("./resources/sound/bass.mp3");

	Color* bgColor = new Color(58, 96, 158);

	game->renderer->init();

	while (!game->window->shouldClose()) {
		game->renderer->setBackgroundColor(bgColor);
		glClear(GL_COLOR_BUFFER_BIT);

		game->window->update();
	}

	glfwTerminate();

	return 0;
}