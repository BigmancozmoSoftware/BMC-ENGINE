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

	files->ReadFile("GameSettings.h");

	float color = 0;

	renderer->init();
	while (!window->shouldClose()) {
		if (keyboard->isKeyDown(GLFW_KEY_UP)) {
			color += 5;
		}

		if (keyboard->isKeyDown(GLFW_KEY_DOWN)) {
			color -= 5;
		}

		color = math->clamp(0, 255, color);

		renderer->setBackgroundColor(0, color, 255);
		glClear(GL_COLOR_BUFFER_BIT);

		window->update();
	}

	glfwTerminate();

	return 0;
}