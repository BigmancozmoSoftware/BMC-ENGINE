#pragma once
#include "../BMCEngine.h"
#include "../../GameSettings.h"

class Game
{
public:
	Game();

	Audio* audio;
	Window* window;
	Renderer* renderer;
	Math* math;
	FileManager* files;
	KeyboardInput* keyboard;
	MouseInput* mouse;
};

