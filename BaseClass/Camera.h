#pragma once

#include "../lib.h"

class Camera {
private:
    // normalized direction vector (cos, sin, sin)
    float dirX;
    float dirY;
    float dirZ;

    // monitor tilt angle (X-axis Based on degree)
    float rotX = 0.0f;
    float rotY = 0.0f;

    // position vector (x, y, z)
    float movX;
    float movY;
    float movZ;

    float rotSpeed = 0.1f;
    float movSpeed = 0.05f;

    float fov = 90.0f;
    float minDist = 0.1f;
    float maxDist = 100.0f;

public:
    Camera(
        float posX, float posY, float posZ,
        float dirX, float dirY, float dirZ
    ) :
        movX(posX), movY(posY), movZ(posZ)
    {
        setDir(dirX, dirY, dirZ);
    }

    void setDir(float x, float y, float z);

    void addRot(float x, float y);
    void addMov(float x, float y, float z);

    void setRotSpeed(float speed);
    void setMovSpeed(float speed);

    void setFov(float angle);
    void setMinDist(float dist);
    void setMaxDist(float dist);

    float getDirX();
    float getDirY();
    float getDirZ();

    float getRotX();
    float getRotY();

    float getMovX();
    float getMovY();
    float getMovZ();

    float getRotSpeed();
    float getMovSpeed();

    float getFov();
    float getMinDist();
    float getMaxDist();

    glm::highp_mat4 getRotMat();
    glm::highp_mat4 getMovMat();
    glm::highp_mat4 getPerspectiveMat(uint32_t width, uint32_t height);
};