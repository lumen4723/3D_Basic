#include "Window.h"

#include "lib.h"

#include "Input.h"
#include "Chara.h"
#include "Bullet.h"
#include "Tools.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

void Init_Comp(vector<Chara> &players, vector<Bullet> &bullets);
void Update_Comp(vector<Chara> &players, vector<Bullet> &bullets);

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
    vector<Chara> players;
    vector<Bullet> bullets;
    Init_Comp(players, bullets);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // TODO: Update Actors And Resources
        processInput(window, &players[0]);

        Update_Comp(players, bullets);

        // TODO: Make Vertex Frame Buffer And Indices From Actors And Resources
        makeVertexFrame(engine->vertices, engine->indices, players, bullets);
        
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
    vector<Vertex>& vertices, vector<uint16_t>& indices,
    vector<Chara>& players, vector<Bullet>& bullets
) {
    vertices.clear();
    indices.clear();

    for (int i = 0; i < players.size(); i++) {
        double x = players[i].get_posX();
        double y = players[i].get_posY();
        float r = players[i].get_color()[0];
        float g = players[i].get_color()[1];
        float b = players[i].get_color()[2];

        vertices.push_back(Vertex(glm::vec3(x - 0.5f, y - 0.5f, 0.0f), glm::vec3(r, g, b)));
        vertices.push_back(Vertex(glm::vec3(x + 0.5f, y - 0.5f, 0.0f), glm::vec3(r, g, b)));
        vertices.push_back(Vertex(glm::vec3(x + 0.5f, y + 0.5f, 0.0f), glm::vec3(r, g, b)));
        vertices.push_back(Vertex(glm::vec3(x - 0.5f, y + 0.5f, 0.0f), glm::vec3(r, g, b)));

        int offset = vertices.size() - 4;

        indices.push_back(offset + 0);
        indices.push_back(offset + 1);
        indices.push_back(offset + 2);
        indices.push_back(offset + 2);
        indices.push_back(offset + 3);
        indices.push_back(offset + 0);
    }

    for (int i = 0; i < bullets.size(); i++) {
        double x = bullets[i].get_posX();
        double y = bullets[i].get_posY();
        float r = bullets[i].get_color()[0];
        float g = bullets[i].get_color()[1];
        float b = bullets[i].get_color()[2];

        vertices.push_back(Vertex(glm::vec3(x - 0.2f, y - 0.2f, 0.0f), glm::vec3(r, g, b)));
        vertices.push_back(Vertex(glm::vec3(x + 0.2f, y - 0.2f, 0.0f), glm::vec3(r, g, b)));
        vertices.push_back(Vertex(glm::vec3(x + 0.2f, y + 0.2f, 0.0f), glm::vec3(r, g, b)));
        vertices.push_back(Vertex(glm::vec3(x - 0.2f, y + 0.2f, 0.0f), glm::vec3(r, g, b)));

        int offset = vertices.size() - 4;

        indices.push_back(offset + 0);
        indices.push_back(offset + 1);
        indices.push_back(offset + 2);
        indices.push_back(offset + 2);
        indices.push_back(offset + 3);
        indices.push_back(offset + 0);
    }
}

void Init_Comp(vector<Chara> &players, vector<Bullet> &bullets) {
    // 초기화 로직

    // 내 첫 위치는 서버로부터 받아온 값으로 설정할 것
    players.push_back(Chara("Me", 100, 0.0f, 0.0f, {1.0f, 0.0f, 0.0f}));

    // 상대는 아래 반복문 내에서 소켓을 통해 동적으로 받아올 것
    players.push_back(Chara("Enemy1", 100, rand() % 400 / 100.0f - 0.0f, rand() % 400 / 100.0f - 0.0f, {0.0f, 1.0f, 0.0f}));
    players.push_back(Chara("Enemy2", 100, rand() % 400 / 100.0f - 0.0f, rand() % 400 / 100.0f - 0.0f, {0.0f, 0.0f, 1.0f}));
}

void Update_Comp(vector<Chara> &players, vector<Bullet> &bullets) {
    // 메인 업데이트 로직

    // 상대의 실시간 정보는 소켓을 통해 받아올 것
    // players[i].add_pos(readsock...x, readsock...y);

    // for (int i = 1; i < players.size(); i++) {
    //     players[i].add_pos(rand() % 10 / 100.0f - 0.2f, rand() % 10 / 100.0f - 0.2f);
    // }

    // 로직 구현
    for (int i = 0; i < players.size(); i++) {
        if (players[i].get_hp() <= 0) {
            cout << players[i].get_name() << " is dead" << endl;
            players.erase(players.begin() + i--);
            continue;
        }
        else if (players[i].get_actionState() == State::action::ATTACKING) {
            bullets.push_back(Bullet(
                players[i].get_posX(),
                players[i].get_posY(),
                0.05,
                players[i].get_attack_dir().first,
                players[i].get_attack_dir().second,
                {1.0f, 1.0f, 1.0f},
                players[i].get_name()
            ));

            players[i].set_actionState(State::action::ATTACKDELAY);
            // 비동기 타이머를 통해 1초 후에 다시 ATTACKABLE로 변경
            thread t([](Chara *player) {
                this_thread::sleep_for(1s);
                player->set_actionState(State::action::ATTACKABLE);
            }, &players[i]);

            t.detach();
        }
    }

    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].move();

        if (
            bullets[i].get_posX() < -14.0
            || bullets[i].get_posX() > 14.0
            || bullets[i].get_posY() < -8.0
            || bullets[i].get_posY() > 8.0
        ) {
            bullets.erase(bullets.begin() + i--);
            continue;
        }
        
        for (int j = 0; j < players.size(); j++) {
            if (
                bullets[i].get_shooterName() != players[j].get_name() // 자신이 쏜거에 대한 충돌은 무시
                && Check_Collision_CB(players[j], bullets[i])  // 충돌 검사, Chara, Bullet 순서임
            ) {
                players[j].damaged(10);
                if (players[j].get_hp() <= 0) {
                    cout << players[j].get_name() << " is dead" << endl;
                    players.erase(players.begin() + j--);
                }

                bullets.erase(bullets.begin() + i--);
                break;
            }
        }
    }
}
