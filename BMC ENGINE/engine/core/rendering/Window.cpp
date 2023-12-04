#include "Window.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "../../../GameSettings.h"
#include <glad/glad.h>

float WtoHmultiplier, HtoWmultiplier;
float globalW, globalH;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	float w = height * HtoWmultiplier;
	float w_diff = globalW - w;
    glViewport(w_diff / 2, 0, w, height);

#if SETTINGS_ANTIALIASING
	glEnable(GL_MULTISAMPLE);
#endif
}

Window::Window(int w, int h, const char* title)
{
	width = w;
	height = h;

	std::cout << "Window created." << std::endl;

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* vidMode = glfwGetVideoMode(monitor);

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if SETTINGS_ANTIALIASING
	glfwWindowHint(GLFW_SAMPLES, SETTINGS_ANTIALIASING_LEVEL);
#endif

	if (width == 0) {
		width = vidMode->width * 0.9;
	}
	if (height == 0) {
		height = vidMode->height * 0.8;
	}

	WtoHmultiplier = ((float)height) / ((float)width);
	HtoWmultiplier = ((float)width) / ((float)height);
	globalW = width;
	globalH = height;
	
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	int img_width, img_height;
	int channels;
	unsigned char* pixels = stbi_load("./resources/images/logo/bmcenginelogo_64x.png", &img_width, &img_height, &channels, 4);

	if (stbi_failure_reason()) {
		std::cout << "Image failed to load: " << stbi_failure_reason() << std::endl;
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

void Window::close()
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLFWwindow* Window::getWindow()
{
	return window;
}
