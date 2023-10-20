#include "../Game.h"

Game::Game()
{
	audio = new Audio();
	//renderer = new Renderer();
	math = new Math();
	window = new Window(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, GAME_WINDOW_TITLE);
	files = new FileManager();
	keyboard = new KeyboardInput(window->getWindow());
	mouse = new MouseInput(window->getWindow());
}
