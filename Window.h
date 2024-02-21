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
        char path[MAX_PATH];
        GetModuleFileName(NULL, path, MAX_PATH);
        return filesystem::path(path).parent_path();
    }();

    GLFWwindow* window;
    VKengine* engine;

    Window(); // <= void initWindow();

    void initVulkan();

    void mainLoop();

    void cleanup();
};