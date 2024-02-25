#include "Camera.h"

void Camera::setDir(float x, float y, float z) {
    float len = sqrt(x * x + y * y + z * z);
    dirX = x / len;
    dirY = y / len;
    dirZ = z / len;
}

void Camera::addRot(float x, float y) {
    rotX += x;
    rotX = (rotX > 360) ? rotX - 360 : rotX;
    rotX = (rotX < 0) ? rotX + 360 : rotX;
    rotY += y;
    rotY = (rotY > 90) ? 90 : rotY;
    rotY = (rotY < -90) ? -90 : rotY;
}

void Camera::addMov(float x, float y, float z) {
    movX += x * dirX + y * dirY;
    movY += x * dirY - y * dirX;
    movZ += z;
}

void Camera::setRotSpeed(float speed) {
    rotSpeed = speed;
}

void Camera::setMovSpeed(float speed) {
    movSpeed = speed;
}

void Camera::setFov(float angle) {
    fov = angle;
}

void Camera::setMinDist(float dist) {
    minDist = dist;
}

void Camera::setMaxDist(float dist) {
    maxDist = dist;
}

float Camera::getDirX() {
    return dirX;
}

float Camera::getDirY() {
    return dirY;
}

float Camera::getDirZ() {
    return dirZ;
}

float Camera::getRotX() {
    return rotX;
}

float Camera::getRotY() {
    return rotY;
}

float Camera::getMovX() {
    return movX;
}

float Camera::getMovY() {
    return movY;
}

float Camera::getMovZ() {
    return movZ;
}

float Camera::getRotSpeed() {
    return rotSpeed;
}

float Camera::getMovSpeed() {
    return movSpeed;
}

float Camera::getFov() {
    return fov;
}

float Camera::getMinDist() {
    return minDist;
}

float Camera::getMaxDist() {
    return maxDist;
}

glm::highp_mat4 Camera::getRotMat() {
    return (
        glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f))
    );
}

glm::highp_mat4 Camera::getMovMat() {
    return (
        glm::lookAt(
            glm::vec3(movX, movY, movZ),
            glm::vec3(movX + dirX, movY + dirY, movZ + dirZ),
            glm::vec3(0.0f, 0.0f, 1.0f)
        )
    );
}

glm::highp_mat4 Camera::getPerspectiveMat(uint32_t width, uint32_t height) {
    return glm::perspective(
        glm::radians(fov),
        width / (float)height,
        minDist, maxDist
    );
}

void Camera::setCollider(Collider *collider) {
    this->collider = collider;
}

void Camera::setRigidbody(Rigidbody *rigidbody) {
    this->rigidbody = rigidbody;
}

Collider *Camera::getCollider() {
    return collider;
}

Rigidbody *Camera::getRigidbody() {
    return rigidbody;
}
