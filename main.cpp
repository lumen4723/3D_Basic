#include "lib.h"

#include "CustomVK/Window.h"

int main() {
    try {
        Window app(1600, 900, "3D FPS");
        app.initVulkan();
        app.mainLoop();
        app.cleanup();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
