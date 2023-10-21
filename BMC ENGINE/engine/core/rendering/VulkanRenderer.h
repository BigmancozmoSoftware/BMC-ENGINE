#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <vector>
#include <iostream>

using namespace std;

class VulkanRenderer
{
public:
	VulkanRenderer();
	void loadVulkan();
	~VulkanRenderer();
private:
	VkInstance instance;
	VkApplicationInfo appInfo{};
	VkInstanceCreateInfo createInfo{};
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	uint32_t extensionCount = 0;

	void getExtensions();
	void checkCompatibility();
	void createInstance();
	bool validationLayersEnabled();
	bool checkValidationLayerSupport();
};
