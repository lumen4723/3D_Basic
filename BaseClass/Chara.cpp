#include "Chara.h"

void Chara::setDir(float x, float y, float z) {
    this->dirX = x;
    this->dirY = y;
    this->dirZ = z;
}

void Chara::addMov(float x, float y, float z) {
    this->movX += x;
    this->movY += y;
    this->movZ += z;
}

void Chara::setMovSpeed(float speed) {
    this->movSpeed = speed;
}

float Chara::getDirX() {
    return this->dirX;
}

float Chara::getDirY() {
    return this->dirY;
}

float Chara::getDirZ() {
    return this->dirZ;
}

float Chara::getMovX() {
    return this->movX;
}

float Chara::getMovY() {
    return this->movY;
}

float Chara::getMovZ() {
    return this->movZ;
}

float Chara::getMovSpeed() {
    return this->movSpeed;
}

void Chara::setCollider(Collider *collider) {
    this->collider = collider;
}

void Chara::setRigidbody(Rigidbody *rigidbody) {
    this->rigidbody = rigidbody;
}

Collider *Chara::getCollider() {
    return this->collider;
}

Rigidbody *Chara::getRigidbody() {
    return this->rigidbody;
}
