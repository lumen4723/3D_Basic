#include "Tools.h"

pair<double, double> Convert_Coordinate(
    pair<double, double> pos, bool pos_is_GLFWCoordinate,
    uint32_t width, uint32_t height,
    double camDistence, double camFov
) {
    double whRatio = width / (double)height;
    double vk_MinCoord = camDistence * tan(camFov / 360 * M_PI);

    if (pos_is_GLFWCoordinate) {
        return {
            (pos.first / (double)width - 0.5) * 2 * whRatio * vk_MinCoord,
            (0.5 - pos.second / (double)height) * 2 * vk_MinCoord
        };
    } 
    else {
        return {
            (pos.first / (2 * whRatio * vk_MinCoord) + 0.5) * width,
            (0.5 - pos.second / (2 * vk_MinCoord)) * height
        };
    }
}

bool Check_Collision_CB(Chara player, Bullet bullet)
{
    if (
        player.get_posX() - 0.5 < bullet.get_posX() + 0.2
        && bullet.get_posX() - 0.2 < player.get_posX() + 0.5
        && player.get_posY() - 0.5 < bullet.get_posY() + 0.2
        && bullet.get_posY() - 0.2 < player.get_posY() + 0.5
    ) {
        return true;
    }

    return false;
}

bool Check_Collision_CC(Chara player1, Chara player2) {
    if (
        player1.get_posX() - 0.5 < player2.get_posX() + 0.5
        && player2.get_posX() - 0.5 < player1.get_posX() + 0.5
        && player1.get_posY() - 0.5 < player2.get_posY() + 0.5
        && player2.get_posY() - 0.5 < player1.get_posY() + 0.5
    ) {
        return true;
    }
    
    return false;
}
