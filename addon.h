#pragma once
#include"SFML/Graphics.hpp"
using namespace sf;

class Addon
{
public:
    Texture tex;
    Sprite tex_load;
    bool drop = false;
    bool status = true;
    bool addon;
    bool liveplus = false;
    bool danger = false;
    bool shield = false;
    bool shooter = false;
    Addon() :addon(false) {}

};
class Lives :public Addon
{
public:
    Lives() :Addon() {
        addon = true;
        liveplus = true;
        tex.loadFromFile("img/life.png");
        tex_load.setTexture(tex);
        tex_load.setPosition(350, -50);
    }

};
class Danger :public Addon
{
public:
    Danger() :Addon() {
        addon = true;
        danger = true;
        tex.loadFromFile("img/danger.png");
        tex_load.setTexture(tex);
        tex_load.setScale(0.10, 0.10);
        tex_load.setPosition(390, -50);
    }

};
class Shooter :public Addon
{
public:
    Shooter() :Addon() {
        addon = true;
        shooter = true;
        tex.loadFromFile("img/shooter.png");
        tex_load.setTexture(tex);
        tex_load.setScale(0.08, 0.08);
        tex_load.setPosition(350, -50);
    }

};
class Shield :public Addon
{
public:
    Shield() :Addon() {
        addon = true;
        shield = true;
        tex.loadFromFile("img/shield.png");
        tex_load.setTexture(tex);
        tex_load.setScale(0.1, 0.1);
        tex_load.setPosition(390, -50);
    }

};
