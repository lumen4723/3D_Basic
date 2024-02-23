#pragma once

#include "lib.h"
#include "Chara.h"
#include "Bullet.h"

// pos는 좌표, pos_is_GLFWCoordinate는
// GLFW 좌표계를 Vulkan 좌표계로 변환할지 (==True),
// Vulkan 좌표계를 GLFW 좌표계로 변환할지 (==False) 결정
// width, height는 GLFW창의 너비와 높이,
// camDistence는 카메라와 물체 사이의 거리, camFov는 카메라의 시야각
pair<double, double> Convert_Coordinate(
    pair<double, double> pos,
    bool pos_is_GLFWCoordinate,
    uint32_t width, uint32_t height,
    double camDistence, double camFov
);

bool Check_Collision_CB(
    Chara player,
    Bullet bullet
);

bool Check_Collision_CC(
    Chara player1,
    Chara player2
);
