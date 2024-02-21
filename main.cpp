#include "lib.h"

#include "Window.h"

int main() {
    try {
        Window app;
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
