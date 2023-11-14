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

	cout << "" << endl;

	Color* bgColor = new Color(58, 96, 158);

	string vertexShaderStr = game->files->ReadFile("./resources/shaders/default/vertexShader.vert");
	string fragmentShaderStr = game->files->ReadFile("./resources/shaders/default/fragmentShader.frag");
	const char* vertexShaderSource = vertexShaderStr.c_str();
	const char* fragmentShaderSource = fragmentShaderStr.c_str();

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};


	while (!glfwWindowShouldClose(game->window->getWindow())) {
		game->window->update();
	}
	
	game->~Game();

	return 0;
}
