#include "Input.h"

#include "../lib.h"

void processInput(GLFWwindow *window, Camera &camera) {
    // 키보드 입력
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.addMov(camera.getMovSpeed(), 0.0f, 0.0f);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.addMov(-camera.getMovSpeed(), 0.0f, 0.0f);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.addMov(0.0f, camera.getMovSpeed(), 0.0f);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.addMov(0.0f, -camera.getMovSpeed(), 0.0f);
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        camera.addMov(0.0f, 0.0f, camera.getMovSpeed());
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
        camera.addMov(0.0f, 0.0f, -camera.getMovSpeed());
    }

    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_RELEASE) {
        double mposX, mposY; // 마우스좌표를 GLFW 좌표계로 받음 (좌 상단이 0, 0)
        glfwGetCursorPos(window, &mposX, &mposY);

        int width, height; // GLFW 창의 크기를 받음 (즉, 우 하단 좌표가 됨)
        glfwGetWindowSize(window, &width, &height);

        // 윈도우 좌표의 차이 값을 degree로 변환
        camera.addRot(
            (width / 2.0 - mposX) * camera.getRotSpeed(),
            (height / 2.0 - mposY) * camera.getRotSpeed()
        );

        camera.setDir(
            cos(glm::radians(camera.getRotX())),
            sin(glm::radians(camera.getRotX())),
            sin(glm::radians(camera.getRotY()))
        );
        glfwSetCursorPos(window, width / 2.0, height / 2.0); // 마우스를 중앙으로 옮김
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // 마우스 커서를 숨김
    }
    else if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); // 마우스 커서를 보이게 함
    }

    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
    }

    if (
        glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE
        && glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE
        && glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE
        && glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE
    ) {
    }

    // ESC 키를 누르면 창을 닫는다
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
