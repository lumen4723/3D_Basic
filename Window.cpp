#include "Window.h"

#include "lib.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Window::Window(
    uint32_t width, uint32_t height, string title
) : WIDTH(width), HEIGHT(height) {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    
    window = glfwCreateWindow(WIDTH, HEIGHT, title.c_str(), nullptr, nullptr);

    GLFWimage Logo[1];
    Logo[0].width = 16;
    Logo[0].height = 16;
    Logo[0].pixels = stbi_load(
        (rootPath / "icon.jpg").string().c_str(),
        &Logo[0].width, &Logo[0].height, 0, 4
    );
    if (Logo[0].pixels == NULL) {
        throw runtime_error("Failed to load Logo image");
    }
    glfwSetWindowIcon(window, 1, Logo);

    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

void Window::initVulkan() {
    engine = new VKengine(window, MAX_FRAMES_IN_FLIGHT, rootPath);
}

void Window::mainLoop() {
    // TODO: Init Actors And Resources

    // 마우스를 지움
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    int width, height; // GLFW 창의 크기를 받음 (즉, 우 하단 좌표가 됨)
    glfwGetWindowSize(window, &width, &height);
    glfwSetCursorPos(window, width / 2, height / 2); // 마우스를 중앙으로 옮김

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // TODO: Update Actors And Resources
        processInput(window, engine->mainCam);

        // TODO: Make Vertex Frame Buffer And Indices From Actors And Resources
        makeVertexFrame(engine->vertices, engine->indices);
        
        engine->drawFrame();
    }

    vkDeviceWaitIdle(engine->device);
}

void Window::cleanup() {
    engine->vkCleanup();

    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::makeVertexFrame(
    vector<Vertex>& vertices, vector<uint16_t>& indices
) {
    vertices = {
        {{-100.0f, -100.0f, 0.0f}, {1.0f, 0.0f, 0.0f}}, // 좌하단 빨강
        {{100.0f, -100.0f, 0.0f}, {0.0f, 1.0f, 0.0f}}, // 우하단 초록
        {{100.0f, 100.0f, 0.0f}, {0.0f, 0.0f, 1.0f}}, // 우상단 파랑
        {{-100.0f, 100.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}, // 좌상단 흰색
    };
    indices = { // Right-Hand Triangle
        0, 1, 2, 2, 3, 0,
    };
}
