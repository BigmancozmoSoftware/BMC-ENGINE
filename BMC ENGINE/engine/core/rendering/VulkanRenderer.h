#pragma once

#define GLFW_INCLUDE_VULKAN
#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_EXPOSE_NATIVE_WIN32

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <vulkan/vulkan.h>
#include <vector>
#include <iostream>
#include "../../framework/Game.h"

using namespace std;

class VulkanRenderer
{
public:
	VulkanRenderer(Game* game);
	void loadVulkan(Game* game);
	~VulkanRenderer();
private:
	VkInstance instance;
	VkApplicationInfo appInfo{};
	VkInstanceCreateInfo createInfo{};
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	uint32_t extensionCount = 0;
	const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"
	};
	std::vector <const char*> getRequiredExtensions();
	VkSurfaceKHR surface;

	void getExtensions();
	void checkCompatibility();
	void createInstance();
	bool validationLayersEnabled();
	bool checkValidationLayerSupport();
	void createSurface(Game* game);
};
