#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Bomb {
public:

	Texture monster_tex;
	Sprite monster_lazer;

	Texture dragon_tex1;
	Sprite dragon_lazer1;

	Texture dragon_tex2;
	Sprite dragon_lazer2;

	Texture dragon_tex3;
	Sprite dragon_lazer3;

	Texture tex;

	const int num = 100;
	Sprite* sprites = new Sprite[num];
	bool* actives = new bool[num];

	Bomb()
	{
		monster_tex.loadFromFile("img/laser.png");
		monster_lazer.setTexture(monster_tex);
		monster_lazer.setScale(2.5, 20);

		dragon_tex1.loadFromFile("img/90.png");
		dragon_lazer1.setTexture(dragon_tex1);
		dragon_lazer1.setScale(3, 15);

		dragon_tex2.loadFromFile("img/1.png");
		dragon_lazer2.setTexture(dragon_tex2);
		dragon_lazer2.setScale(0.5, 6);

		dragon_tex3.loadFromFile("img/3.png");
		dragon_lazer3.setTexture(dragon_tex3);
		dragon_lazer3.setScale(0.5, 6);



		tex.loadFromFile("img/bomb.png");
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
				sprites[i].move(0, 0.3);
			}
		}
	}


	void Mshow(RenderWindow& win) {

		win.draw(monster_lazer);

	}

	void Mfire(int x, int y) {

		monster_lazer.setPosition(x, y);

	}

	void Dshow1(RenderWindow& win) {

		win.draw(dragon_lazer1);

	}

	void Dfire1(int x, int y) {

		dragon_lazer1.setPosition(x, y);

	}

	void Dshow2(RenderWindow& win) {

		win.draw(dragon_lazer2);

	}

	void Dfire2(int x, int y) {

		dragon_lazer2.setPosition(x + 120, y + 10);

	}
	void Dshow3(RenderWindow& win) {

		win.draw(dragon_lazer3);

	}

	void Dfire3(int x, int y) {

		dragon_lazer3.setPosition(x - 10, y + 10);

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
	~Bomb() // Destructor to free dynamically allocated memory
	{
		delete[] sprites;
		delete[] actives;
	}

};
