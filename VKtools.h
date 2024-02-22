#pragma once

#include "lib.h"

static vector<char> readFile(const string& filename) {
    ifstream file(filename, ios::ate | ios::binary);

    if (!file.is_open()) {
        throw runtime_error("failed to open file!");
    }

    size_t fileSize = (size_t) file.tellg();
    vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();

    return buffer;
}

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData
) {
    cerr << "validation layer: " << pCallbackData->pMessage << endl;

    return VK_FALSE;
}


VkResult CreateDebugUtilsMessengerEXT(
    VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
    const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger
);

void DestroyDebugUtilsMessengerEXT(
    VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger,
    const VkAllocationCallbacks* pAllocator
);

void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);


VkShaderModule createShaderModule(const vector<char> &code, VkDevice device);


VkSurfaceFormatKHR chooseSwapSurfaceFormat(
    const vector<VkSurfaceFormatKHR> &availableFormats
);

VkPresentModeKHR chooseSwapPresentMode(
    const vector<VkPresentModeKHR> &availablePresentModes
);

VkExtent2D chooseSwapExtent(
    const VkSurfaceCapabilitiesKHR &capabilities,
    GLFWwindow* window
);

SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device, VkSurfaceKHR surface);


bool checkDeviceExtensionSupport(
    VkPhysicalDevice device, const vector<const char *> &deviceExtensions
);

bool isDeviceSuitable(
    VkPhysicalDevice device, VkSurfaceKHR surface,
    const vector<const char *> &deviceExtensions
);

vector<const char *> getRequiredExtensions(bool enableValidationLayers);

bool checkValidationLayerSupport(const vector<const char*> &validationLayers);


QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device, VkSurfaceKHR surface);
