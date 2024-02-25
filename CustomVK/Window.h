#pragma once

#include "../lib.h"

#include "VKengine.h"
#include "VKtools.h"
#include "../BaseClass/Input.h"

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

    Window(uint32_t width = 800, uint32_t height = 600, string title = "3D Basic");

    void initVulkan();

    void mainLoop();

    void cleanup();
    
    void makeVertexFrame(
        vector<Vertex>& vertices, vector<uint16_t>& indices,
        vector<Chara>& charas
    );
};

static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    VKengine* app = reinterpret_cast<VKengine*>(glfwGetWindowUserPointer(window));
    app->framebufferResized = true;
}
