#pragma once
#include "../../GameSettings.h"
#include "../BMCEngine.h"

class Game
{
public:
	Game();
	Audio* audio;
	Window* window;
	Math* math;
	FileManager* files;
	KeyboardInput* keyboard;
	MouseInput* mouse;
	Renderer_OpenGL* renderer;
	~Game();
};

