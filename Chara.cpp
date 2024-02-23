#include "Chara.h"

#include "lib.h"

Chara::Chara(
    string name,
    int hp,
    double posX,
    double posY,
    vector<float> color
) {
    this->name = name;
    this->hp = hp;
    this->posX = posX;
    this->posY = posY;
    this->color = color;
    move = State::IDLE;
    action = State::ATTACKABLE;
}

Chara::~Chara() {}

void Chara::set_name(string name) {
    this->name = name;
}

void Chara::set_hp(int hp) {
    this->hp = hp;
}

void Chara::set_posX(double posX) {
    this->posX = posX;
}

void Chara::set_posY(double posY) {
    this->posY = posY;
}

void Chara::set_speed(double speed) {
    this->speed = speed;
}

string Chara::get_name() {
    return name;
}

int Chara::get_hp() {
    return hp;
}

double Chara::get_posX() {
    return posX;
}

double Chara::get_posY() {
    return posY;
}

double Chara::get_speed() {
    return speed;
}

void Chara::add_pos(double x, double y) {
    this->posX += x;
    this->posY += y;
}

vector<float> Chara::get_color() {
    return color;
}

void Chara::set_moveState(State::move move) {
    this->move = move;
}

void Chara::set_actionState(State::action action) {
    this->action = action;
}

State::move Chara::get_moveState() {
    return move;
}

State::action Chara::get_actionState() {
    return action;
}

void Chara::set_attack_dir(double x, double y) {
    attack_dir = make_pair(x, y);
}

pair<double, double> Chara::get_attack_dir() {
    return attack_dir;
}

void Chara::damaged(int damage) {
    hp -= damage;
}