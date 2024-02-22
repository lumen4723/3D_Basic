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

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // TODO: Update Actors And Resources
        

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
        {{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
        {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}},
        {{-0.5f, 0.5f, 0.0f}, {1.0f, 1.0f, 1.0f}},

        {{0.5f, 0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
        {{1.5f, 0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
        {{1.5f, 1.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, 1.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},

        {{-1.5f, 0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
        {{-0.5f, 0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
        {{-0.5f, 1.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
        {{-1.5f, 1.5f, 0.0f}, {0.0f, 1.0f, 0.0f}}
    };
    indices = { // Right-Hand Triangle
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        8, 9, 10, 10, 11, 8
    };
}
