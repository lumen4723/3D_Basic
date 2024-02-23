#pragma once

#include "lib.h"

class Bullet {
private:
    double startX;
    double startY;
    double posX;
    double posY;
    double speed;
    double dirX;
    double dirY;
    vector<float> color;
    string shooterName;

public:
    Bullet(
        double posX = 0,
        double posY = 0,
        double speed = 0,
        double dirX = 0,
        double dirY = 0,
        vector<float> color = {1.0f, 1.0f, 1.0f},
        string shooterName = "defaultPlayer"
    );
    ~Bullet();

    void set_posX(double posX);
    void set_posY(double posY);
    void set_speed(double speed);
    void set_dirX(double dirX);
    void set_dirY(double dirY);

    double get_posX();
    double get_posY();
    double get_speed();
    double get_dirX();
    double get_dirY();
    vector<float> get_color();
    string get_shooterName();

    void move();

    // double totalmoved();
};