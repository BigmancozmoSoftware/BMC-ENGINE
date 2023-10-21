#include "VulkanRenderer.h"

VulkanRenderer::VulkanRenderer()
{
	loadVulkan();
}

void VulkanRenderer::createInstance()
{
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;

	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
		throw std::runtime_error("failed to create instance!");
	}
}

void VulkanRenderer::loadVulkan()
{
	createInstance();
	getExtensions();
}

void VulkanRenderer::getExtensions()
{
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	std::vector<VkExtensionProperties> extensions(extensionCount);

	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

	cout << "Available Vulkan Extensions:" << endl;

	for (const auto& extension : extensions) {
		cout << '\t' << extension.extensionName << endl;
	}
}

void VulkanRenderer::checkCompatibility()
{
	if (glfwVulkanSupported()) {
		cout << "Vulkan is supported" << endl;
		cout << "" << endl;
	}
}

VulkanRenderer::~VulkanRenderer()
{
	vkDestroyInstance(instance, nullptr);

}
