#include "Collider.h"

void Collider::setMid(float x, float y, float z) {
    this->midX = x;
    this->midY = y;
    this->midZ = z;
}

float Collider::getMidX() {
    return this->midX;
}

float Collider::getMidY() {
    return this->midY;
}

float Collider::getMidZ() {
    return this->midZ;
}

bool Collider::isCollide(Collider *collider) {
    switch (this->type) {
    case Type::Box:
        switch (collider->type) {
        case Type::Box:
            return (
                this->sizeX.first <= collider->sizeX.second && this->sizeX.second >= collider->sizeX.first
                && this->sizeY.first <= collider->sizeY.second && this->sizeY.second >= collider->sizeY.first
                && this->sizeZ.first <= collider->sizeZ.second && this->sizeZ.second >= collider->sizeZ.first
            );
        case Type::Capsule:
            return (
                false
            );
        }
    case Type::Capsule:
        switch (collider->type) {
        case Type::Box:
            return (
                false
            );
        case Type::Capsule:
            return (
                false
            );
        }
    }
}
