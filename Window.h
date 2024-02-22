#pragma once

#include "lib.h"

#include "VKengine.h"
#include "VKtools.h"

class Window {
public:
    const uint32_t WIDTH;
    const uint32_t HEIGHT;

    const int MAX_FRAMES_IN_FLIGHT = 2;

    filesystem::path rootPath = []() {
        wchar_t path[MAX_PATH];
        GetModuleFileNameW(NULL, path, MAX_PATH);
        return filesystem::path(path).parent_path();
    }();

    GLFWwindow* window;
    VKengine* engine;

    Window(uint32_t width = 800, uint32_t height = 600);

    void initVulkan();

    void mainLoop();

    void cleanup();
};

static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    VKengine* app = reinterpret_cast<VKengine*>(glfwGetWindowUserPointer(window));
    app->framebufferResized = true;
}
