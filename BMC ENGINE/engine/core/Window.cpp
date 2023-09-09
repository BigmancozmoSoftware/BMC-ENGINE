#include "Window.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

Window::Window(int width, int height, const char* title)
{
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* vidMode = glfwGetVideoMode(monitor);

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, title, NULL, NULL);
	
	int img_width, img_height;
	int channels;
	unsigned char* pixels = stbi_load("./resources/bmcenginelogo.png", &img_width, &img_height, &channels, 4);

	if (stbi_failure_reason()) {
		std::cout << "Image failed to load: " << stbi_failure_reason() << endl;
	}

	GLFWimage images[1];
	images[0].height = img_height;
	images[0].width = img_width;
	images[0].pixels = pixels;

	glfwSetWindowPos(window, (vidMode->width / 2) - (width / 2), (vidMode->height / 2) - (height / 2));
	glfwShowWindow(window);

	glfwMakeContextCurrent(window);

	glfwSetWindowIcon(window, 1, images);
}

void Window::update()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}

GLFWwindow* Window::getWindow()
{
	return window;
}
