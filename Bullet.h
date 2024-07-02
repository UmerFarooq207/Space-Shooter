#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Bullet {
public:
	int x, y;
	Texture tex;
	const int num = 10;

	Sprite* sprites = new Sprite[num];
	bool* actives = new bool[num];

	Bullet()
	{
		tex.loadFromFile("img/bullet.png");
		for (int i = 0; i < num; i++)
		{
			sprites[i].setTexture(tex);
			actives[i] = 0;
		}
	}


	void fire(int x, int y)
	{
		for (int i = 0; i < num; i++)
			if (!actives[i])
			{
				actives[i] = 1;
				sprites[i].setPosition(x, y);
				this->x = x;
				this->y = y;
				break;
			}
	}

	void show(RenderWindow& win)
	{



		for (int i = 0; i < num; i++)
		{
			if (actives[i])
			{


				win.draw(sprites[i]);
				sprites[i].move(0, -0.5);
			}
		}
	}

	void deactivate()
	{
		for (int i = 0; i < num; i++)
		{
			if (actives[i])
			{
				if (sprites[i].getPosition().y < -10)
					actives[i] = 0;
			}
		}
	}
	~Bullet() // Destructor to free dynamically allocated memory
	{
		delete[] sprites;
		delete[] actives;
	}

};
