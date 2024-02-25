#pragma once 

#include "../lib.h"
#include "Rigidbody.h"
#include "Collider.h"

class Chara {
private:
    // normalized direction vector (cos, sin, sin)
    float dirX;
    float dirY;
    float dirZ;

    // position vector (x, y, z)
    float movX;
    float movY;
    float movZ;

    float movSpeed = 0.05f;

    Collider *collider = nullptr;
    Rigidbody *rigidbody = nullptr;

public:
    Chara(
        float posX, float posY, float posZ,
        float dirX, float dirY, float dirZ
    ) :
        movX(posX), movY(posY), movZ(posZ)
    {
        setDir(dirX, dirY, dirZ);
    }

    void setDir(float x, float y, float z);

    void addMov(float x, float y, float z);

    void setMovSpeed(float speed);

    float getDirX();
    float getDirY();
    float getDirZ();

    float getMovX();
    float getMovY();
    float getMovZ();

    float getMovSpeed();

    void setCollider(Collider *collider);
    void setRigidbody(Rigidbody *rigidbody);

    Collider *getCollider();
    Rigidbody *getRigidbody();
};