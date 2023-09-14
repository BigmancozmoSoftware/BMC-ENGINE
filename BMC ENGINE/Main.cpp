// hi
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

	float red = 0;
	float green = 0;
	
	renderer->init();
	while (!window->shouldClose()) {
		if (keyboard->isKeyDown(GLFW_KEY_UP)) {
			red += 5;
		}

		if (keyboard->isKeyDown(GLFW_KEY_DOWN)) {
			red -= 5;
		}

		if (mouse->leftMouseDown()) {
			green -= 5;
		}

		if (mouse->rightMouseDown()) {
			green += 5;
		}

		red = math->clamp(red, 255, 0);
		green = math->clamp(green, 255, 0);

		renderer->setBackgroundColor(red, green, 255);
		glClear(GL_COLOR_BUFFER_BIT);

		window->update();
	}

	glfwTerminate();

	return 0;
}