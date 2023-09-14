// hi welcome to bmc engine source code

#include "engine/BMCEngine.h"
#include "GameSettings.h"

int main(){
	glfwInit();

	Window* window = new Window(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, GAME_WINDOW_TITLE);
	Renderer* renderer = new Renderer();
	Math* math = new Math();
	FileManager* files = new FileManager();
	KeyboardInput* keyboard = new KeyboardInput(window->getWindow());
	MouseInput* mouse = new MouseInput(window->getWindow());

	cout << files->ReadFile("GameSettings.h") << endl;

	Color* bgColor = new Color(58, 96, 158);
	
	renderer->init();
	while (!window->shouldClose()) {

		renderer->setBackgroundColor(bgColor);
		glClear(GL_COLOR_BUFFER_BIT);

		window->update();
	}

	glfwTerminate();

	return 0;
}