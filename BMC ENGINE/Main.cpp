// hi welcome to bmc engine source code

#include "engine/BMCEngine.h"
#include "GameSettings.h"

#include <chrono>
#include <sys/timeb.h>
#include <ctime>

using namespace std::chrono;

int main(){
	glfwInit();

	Window* window = new Window(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, GAME_WINDOW_TITLE);
	Renderer* renderer = new Renderer();
	Math* math = new Math();
	FileManager* files = new FileManager();
	KeyboardInput* keyboard = new KeyboardInput(window->getWindow());
	MouseInput* mouse = new MouseInput(window->getWindow());

	Color* bgColor = new Color(58, 96, 158);

	high_resolution_clock::time_point previous = high_resolution_clock::now();
	high_resolution_clock::time_point current = high_resolution_clock::now();

	double deltaTime = 0;

	renderer->init();
	while (!window->shouldClose()) {
		current = high_resolution_clock::now();
		duration<double, std::milli> time_span = current - previous;
		deltaTime = time_span.count();

		if (keyboard->isKeyDown(GLFW_KEY_UP)) {
			bgColor->r += (int)(3600 * deltaTime);
		}

		if (keyboard->isKeyDown(GLFW_KEY_DOWN)) {
			bgColor->r -= (int)(3600 * deltaTime);
		}

		renderer->setBackgroundColor(bgColor);
		glClear(GL_COLOR_BUFFER_BIT);

		window->update();

		previous = high_resolution_clock::now();
	}

	glfwTerminate();

	return 0;
}