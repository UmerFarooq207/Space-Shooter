#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
#include "bomb.h"
using namespace sf;
class Enemy {
public:
    int x, y;
    Texture tex;
    Sprite sprite;
    int value;
    Bomb bomb;
    bool status = false;
    float cooldown = 2.0;
    Enemy(int a, int x, int y) : x(x), y(y), status(true) {
        sprite.setPosition(x, y);
        sprite.setScale(0.30, 0.30);
    }

    virtual void form() = 0;

    void fire_enemy() {
        if (cooldown < 0 && status) {
            int x = sprite.getPosition().x + 20;
            int y = sprite.getPosition().y + 12;
            bomb.fire(x, y);
            cooldown = (rand() % 2000) / 100.0;
        }
    }



    void mainloop(RenderWindow& win, float dt) {

        bomb.show(win);

        if (!status)
            return;
        cooldown -= dt;

        bomb.deactivate();
        fire_enemy();
        win.draw(sprite);
    }

    void M_mainloop(RenderWindow& win) {
        if (!status)
            return;
        bomb.Mshow(win);
        int x = sprite.getPosition().x + 79;
        int y = sprite.getPosition().y + 20;
        bomb.Mfire(x, y);
        win.draw(sprite);
    }

    void D_mainloop(RenderWindow& win) {
        if (!status)
            return;
        bomb.Dshow1(win);
        bomb.Dshow2(win);
        bomb.Dshow3(win);
        int x = sprite.getPosition().x + 34;
        int y = sprite.getPosition().y + 200;
        bomb.Dfire1(x, y);
        bomb.Dfire2(x, y);
        bomb.Dfire3(x, y);
        win.draw(sprite);
    }


    ~Enemy() {}

};

class Alpha : public Enemy {
public:


    Alpha(int x = 0, int y = 0) : Enemy(0, x, y) {

    }

    void form() {
        cooldown = 3.0;
        tex.loadFromFile("img/alpha.png");
        sprite.setPosition(x, y);
        sprite.setTexture(tex);
        sprite.setScale(0.30, 0.30);
        this->value = 1;
    }

    ~Alpha() {}
};

class Beta : public Enemy {
public:
    Beta(int x = 0, int y = 0) : Enemy(1, x, y) {

    }

    void form() {
        cooldown = 2.5;
        tex.loadFromFile("img/beta.png");
        sprite.setPosition(x, y);
        sprite.setTexture(tex);
        sprite.setScale(0.25, 0.25);
        this->value = 2;
    }

    ~Beta() {}
};

class Gamma : public Enemy {
public:
    Gamma(int x = 0, int y = 0) : Enemy(2, x, y) {

    }

    void form() {
        cooldown = 2.0;
        tex.loadFromFile("img/gamma.png");
        sprite.setPosition(x, y);
        sprite.setTexture(tex);
        sprite.setScale(0.25, 0.25);
        this->value = 3;
    }

    ~Gamma() {}
};


class Monster : public Enemy {
public:
    Monster(int x = 0, int y = 0) : Enemy(3, x, y) {

    }

    void form() {



        tex.loadFromFile("img/monster2.png");

        sprite.setPosition(x, y);
        sprite.setTexture(tex);
        sprite.setScale(0.15, 0.15);
        this->value = 4;




    }

    ~Monster() {}
};

class Dragon : public Enemy {
public:
    Dragon(int x = 0, int y = 0) : Enemy(4, x, y) {

    }

    void form() {



        tex.loadFromFile("img/dragon2.png");

        sprite.setPosition(x, y);
        sprite.setTexture(tex);
        sprite.setScale(0.45, 0.45);
        this->value = 5;




    }

    ~Dragon() {}
};
