#pragma once
#include "../../GameSettings.h"
#include "../BMCEngine.h"

class Game
{
public:
	Game();
	Audio* audio;
	Window* window;
	//Renderer* renderer;
	Math* math;
	FileManager* files;
	KeyboardInput* keyboard;
	MouseInput* mouse;
};

