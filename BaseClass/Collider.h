#pragma once 

#include "../lib.h"

class Collider {
private:
    enum class Type {
        Box,
        Capsule
    };

    Type type;
    float midX;
    float midY;
    float midZ;

    // Box는 3개의 축을 기준으로 최소, 최대값을 가짐
    // Capsule은 X, Y가 캡슐의 원통 지름 최소, 최대 값, Z가 원통의 길이 최소, 최대 값
    pair<float, float> sizeX;
    pair<float, float> sizeY;
    pair<float, float> sizeZ;

public:
    Collider(
        float x, float y, float z, Type type
    ) :
        midX(x), midY(y), midZ(z), type(type)
    {}

    void setMid(float x, float y, float z);

    float getMidX();
    float getMidY();
    float getMidZ();

    bool isCollide(Collider *collider);
};