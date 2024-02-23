#pragma once

#include "lib.h"

struct State {
    enum move {
        IDLE,
        WALK,
        RUN,
    };
    enum action {
        ATTACKABLE,
        ATTACKING,
        ATTACKDELAY,
    };
};

class Chara {
private:
    string name;
    int hp;

    vector<float> color;

    double posX;
    double posY;
    double speed = 0.025;

    State::move move;
    State::action action;
    pair<double, double> attack_dir;

public:
    Chara(
        string name = "defaultPlayer",
        int hp = 100,
        double posX = 0,
        double posY = 0,
        vector<float> color = {1.0f, 0.0f, 0.0f}
    );
    ~Chara();

    void set_name(string name);
    void set_hp(int hp);
    void set_posX(double posX);
    void set_posY(double posY);
    void set_speed(double speed);

    void add_pos(double x, double y);

    string get_name();
    int get_hp();
    double get_posX();
    double get_posY();
    double get_speed();

    vector<float> get_color();

    void set_moveState(State::move move);
    void set_actionState(State::action action);

    State::move get_moveState();
    State::action get_actionState();

    void set_attack_dir(double x, double y);
    pair<double, double> get_attack_dir();

    void damaged(int damage);
};
