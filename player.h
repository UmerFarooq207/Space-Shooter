#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
#include"Bullet.h"

using namespace sf;
class Player {
public:


	Texture tex;
	Sprite sprite;
	float cooldown = 0;
	float speed = 0.3;
	int x, y;
	bool status;
	Bullet bullet;
	Player(std::string png_path) : status(true)
	{


		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 20; y = 520;
		sprite.setPosition(x, y);
		sprite.setScale(0.65, 0.65);
	}




	void fire()
	{

		if (cooldown < 0 && status)
		{
			int x = sprite.getPosition().x + 30;
			int y = sprite.getPosition().y;
			bullet.fire(x, y);
			cooldown = 0.5;
		}
	}
	void move(std::string s)
	{

		if (!status)
			return;
		float delta_x = 0, delta_y = 0;
		if (s == "l")
			//move the player left
			delta_x = -1;
		else if (s == "r")
			//move the player right
			delta_x = 1;
		if (s == "u")
			delta_y = -1;
		else if (s == "d")
			delta_y = 1;
		if (s == "e") {
			delta_x = 1;
			delta_y = -1;
		}
		else if (s == "q") {
			delta_x = -1;
			delta_y = -1;
		}


		delta_x *= speed;
		delta_y *= speed;
		float temp_x, temp_y;

		temp_x = sprite.getPosition().x + delta_x;
		temp_y = sprite.getPosition().y + delta_y;

		if (temp_x <= -80)
			sprite.setPosition(800, temp_y);
		else if (temp_x >= 800)
			sprite.setPosition(-80, temp_y);
		if (temp_y <= -80)
			sprite.setPosition(temp_x, 600);
		else if (temp_y >= 600)
			sprite.setPosition(temp_x, -80);

		sprite.move(delta_x, delta_y);
	}

	void mainloop(RenderWindow& win, float dt)
	{

		bullet.show(win);

		if (!status)
			return;

		cooldown -= dt;



		bullet.deactivate();

		win.draw(sprite);
	}

};
