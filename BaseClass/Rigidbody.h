#pragma once 

#include "../lib.h"

class Rigidbody {
private:
    float mass;
    float velX;
    float velY;
    float velZ;

    float accelX;
    float accelY;
    float accelZ;

    float friction = 0.1f;
    float gravity = 9.8f;
    float restitution = 0.5f;

public:
    Rigidbody(float mass) : mass(mass) {}

    void setMass(float mass);
    void setVel(float x, float y, float z);
    void setAccel(float x, float y, float z);

    float getMass();
    float getVelX();
    float getVelY();
    float getVelZ();

    float getAccelX();
    float getAccelY();
    float getAccelZ();
};