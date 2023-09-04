#include "engine/BMCEngine.h"

int main(){
	glfwInit();

	Window* window = new Window(800, 600, "BMC Engine");

	while (!window->shouldClose()) {
		window->update();
	}

	return 0;
}