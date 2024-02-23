#include "Input.h"

#include "lib.h"
#include "Tools.h"
#include "Chara.h"

void processInput(GLFWwindow *window, Chara *player) {
    // 키보드 입력
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        player->set_moveState(State::WALK);
        player->add_pos(0, player->get_speed());
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        player->set_moveState(State::WALK);
        player->add_pos(0, -player->get_speed());
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        player->set_moveState(State::WALK);
        player->add_pos(player->get_speed(), 0);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        player->set_moveState(State::WALK);
        player->add_pos(-player->get_speed(), 0);
    }

    // 마우스 입력
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        if (player->get_actionState() == State::ATTACKABLE) {
            // 공격 상태로 전환
            player->set_actionState(State::ATTACKING);

            double mposX, mposY; // 마우스좌표를 GLFW 좌표계로 받음 (좌 상단이 0, 0)
            glfwGetCursorPos(window, &mposX, &mposY);

            int width, height; // GLFW 창의 크기를 받음 (즉, 우 하단 좌표가 됨)
            glfwGetWindowSize(window, &width, &height);

            // VULKAN 좌표계는 화면의 정중앙이 (0, 0)이고 비율도 달라서 변환 해야 함
            // 카메라는 Uniform Buffer의 세팅 값으로, Distence와 Fov를 받아옴
            pair<double, double> pos = Convert_Coordinate({mposX, mposY}, true, width, height, 4.0, 90.0);

            double x = pos.first - player->get_posX();
            double y = pos.second - player->get_posY();

            // 명령 추가
            double sqrtdist = sqrt(x * x + y * y);
            player->set_attack_dir(x / sqrtdist, y / sqrtdist);
        }
    }

    if (
        glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE
        && glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE
        && glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE
        && glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE
    ) {
        player->set_moveState(State::IDLE);
    }

    // ESC 키를 누르면 창을 닫는다
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
