#include "engine/BMCEngine.h"
#include "GameSettings.h"

int main(){
	glfwInit();

	Window* window = new Window(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, GAME_WINDOW_TITLE);
	Renderer* renderer = new Renderer();
	Math* math = new Math();
	
	FileManager* files = new FileManager();

	files->ReadFile("GameSettings.h");

	float color = 0;

	renderer->init();
	while (!window->shouldClose()) {
		if (glfwGetKey(window->getWindow(), GLFW_KEY_UP) == GLFW_PRESS) {
			color += 0.025;
		}

		if (glfwGetKey(window->getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS) {
			color -= 0.025;
		}

		color = math->clamp(0, 1, color);

		glClearColor(color, color, color, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		window->update();
	}

	glfwTerminate();

	return 0;
}