#pragma once 

#include "lib.h"
#include "Camera.h"
#include "VKtools.h"

class VKengine {
private:
    const filesystem::path rootPath;

    const vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

    const vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

    const int MAX_FRAMES_IN_FLIGHT;

    GLFWwindow* window;

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkSurfaceKHR surface;

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    VkQueue graphicsQueue;
    VkQueue presentQueue;

    VkSwapchainKHR swapChain;
    vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    vector<VkImageView> swapChainImageViews;
    vector<VkFramebuffer> swapChainFramebuffers;

    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

    VkCommandPool commandPool;

    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;

    vector<VkBuffer> uniformBuffers;
    vector<VkDeviceMemory> uniformBuffersMemory;
    vector<void*> uniformBuffersMapped;

    VkDescriptorPool descriptorPool;
    vector<VkDescriptorSet> descriptorSets;

    vector<VkCommandBuffer> commandBuffers;

    vector<VkSemaphore> imageAvailableSemaphores;
    vector<VkSemaphore> renderFinishedSemaphores;
    vector<VkFence> inFlightFences;
    uint32_t currentFrame = 0;

public:
    VkDevice device;
    bool framebufferResized = true;

    Camera mainCam = Camera(0.0f, 0.0f, 2.0f, 1.0f, 1.e-20f, 1.e-20f);

    vector<Vertex> vertices = { // 위치, 색깔 초기 값
        {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}}
    };
    vector<uint16_t> indices = {0}; // Right-Hand Triangle

    void createInstance();
    void setupDebugMessenger();
    void createSurface();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createSwapChain();
    void createImageViews();
    void createRenderPass();
    void createDescriptorSetLayout();
    void createGraphicsPipeline();
    void createFramebuffers();
    void createCommandPool();
    void createVertexBuffer();
    void createIndexBuffer();
    void createUniformBuffers();
    void createDescriptorPool();
    void createDescriptorSets();
    void createCommandBuffers();
    void createSyncObjects();

    VKengine(
        GLFWwindow* window,
        const int MAX_FRAMES_IN_FLIGHT,
        filesystem::path& rootPath
    );

    void createBuffer(
        VkDeviceSize size, VkBufferUsageFlags usage,
        VkMemoryPropertyFlags properties, VkBuffer& buffer,
        VkDeviceMemory& bufferMemory
    );

    void vkCleanup();

    void recreateSwapChain();
    void cleanupSwapChain();

    void drawFrame();

    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    void updateUniformBuffer(uint32_t currentImage);
};
