#include "Window.h"

#include "lib.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Window::Window() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    
    window = glfwCreateWindow(WIDTH, HEIGHT, "3D Basic", nullptr, nullptr);

    GLFWimage icons[1];
    icons[0].width = 16;
    icons[0].height = 16;
    icons[0].pixels = stbi_load(
        (rootPath / "icon.jpg").string().c_str(),
        &icons[0].width, &icons[0].height, 0, 4
    );
    if (icons[0].pixels == NULL) {
        throw runtime_error("Failed to load icon image");
    }
    glfwSetWindowIcon(window, 1, icons);

    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

void Window::initVulkan() {
    engine = new VKengine(window, MAX_FRAMES_IN_FLIGHT, rootPath);
}

void Window::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        engine->drawFrame();
    }

    vkDeviceWaitIdle(engine->device);
}

void Window::cleanup() {
    engine->vkCleanup();

    glfwDestroyWindow(window);

    glfwTerminate();
}

