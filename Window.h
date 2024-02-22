#pragma once

#include "lib.h"

#include "VKengine.h"
#include "Tools.h"

class Window {
public:
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    const int MAX_FRAMES_IN_FLIGHT = 2;

    filesystem::path rootPath = []() {
        wchar_t path[MAX_PATH];
        GetModuleFileNameW(NULL, path, MAX_PATH);
        return filesystem::path(path).parent_path();
    }();

    GLFWwindow* window;
    VKengine* engine;

    Window();

    void initVulkan();

    void mainLoop();

    void cleanup();
};

static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    auto app = reinterpret_cast<VKengine*>(glfwGetWindowUserPointer(window));
    app->framebufferResized = true;
}
