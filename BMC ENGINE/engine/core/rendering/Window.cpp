#include "Window.h"

#define STB_IMAGE_IMPLEMENTATION
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#define GLFW_NATIVE_INCLUDE_NONE

#include "stb/stb_image.h"
#include "../../../GameSettings.h"
#include <glad/glad.h>
#include <Windows.h>
#include "GLFW/glfw3native.h"

float WtoHmultiplier, HtoWmultiplier;
float globalW, globalH;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	int newWidth = width;
	int newHeight = static_cast<int>(width * 9.0 / 16.0);
	if (newHeight > height) {
		newHeight = height;
		newWidth = static_cast<int>(height * 16.0 / 9.0);
	}
	glViewport((width - newWidth) / 2, (height - newHeight) / 2, newWidth, newHeight);

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

	HWND hwnd = glfwGetWin32Window(window);
	long dwStyle = GetWindowLong(hwnd, GWL_STYLE);
	dwStyle ^= WS_MAXIMIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, dwStyle);

#if USE_BETA_MENU
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
#endif
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
