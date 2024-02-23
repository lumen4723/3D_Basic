#include "Bullet.h"

Bullet::Bullet(
    double posX,
    double posY,
    double speed,
    double dirX,
    double dirY,
    vector<float> color,
    string shooterName
) {
    this->startX = posX;
    this->startY = posY;
    this->posX = posX;
    this->posY = posY;
    this->speed = speed;
    this->dirX = dirX;
    this->dirY = dirY;
    this->color = color;
    this->shooterName = shooterName;
}

Bullet::~Bullet() {}

void Bullet::set_posX(double posX) {
    this->posX = posX;
}

void Bullet::set_posY(double posY) {
    this->posY = posY;
}

void Bullet::set_speed(double speed) {
    this->speed = speed;
}

void Bullet::set_dirX(double dirX) {
    this->dirX = dirX;
}

void Bullet::set_dirY(double dirY) {
    this->dirY = dirY;
}

double Bullet::get_posX() {
    return posX;
}

double Bullet::get_posY() {
    return posY;
}

double Bullet::get_speed() {
    return speed;
}

double Bullet::get_dirX() {
    return dirX;
}

double Bullet::get_dirY() {
    return dirY;
}

vector<float> Bullet::get_color() {
    return color;
}

string Bullet::get_shooterName() {
    return shooterName;
}

void Bullet::move() {
    this->posX += this->dirX * this->speed;
    this->posY += this->dirY * this->speed;
}

// double Bullet::totalmoved() {
//     return sqrt(
//         pow(this->posX - this->startX, 2) +
//         pow(this->posY - this->startY, 2)
//     );
// }