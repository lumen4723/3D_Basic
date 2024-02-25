#include "Rigidbody.h"

void Rigidbody::setMass(float mass) {
    this->mass = mass;
}

void Rigidbody::setVel(float x, float y, float z) {
    this->velX = x;
    this->velY = y;
    this->velZ = z;
}

void Rigidbody::setAccel(float x, float y, float z) {
    this->accelX = x;
    this->accelY = y;
    this->accelZ = z;
}

float Rigidbody::getMass() {
    return this->mass;
}

float Rigidbody::getVelX() {
    return this->velX;
}

float Rigidbody::getVelY() {
    return this->velY;
}

float Rigidbody::getVelZ() {
    return this->velZ;
}

float Rigidbody::getAccelX() {
    return this->accelX;
}

float Rigidbody::getAccelY() {
    return this->accelY;
}

float Rigidbody::getAccelZ() {
    return this->accelZ;
}
