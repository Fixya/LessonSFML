#pragma once
#include "settings.h"

class Meteor {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;
	int damage;

public:
	static std::string mFileNames[];
	static int arrDamage[];
	Meteor() {
		int index = rand() % 4;
		damage = arrDamage[index];
		texture.loadFromFile(IMAGES_FOLDER + mFileNames[index]);
		sprite.setTexture(texture);
		spawn();
	}

	void spawn() {
		float meteorWidth = sprite.getLocalBounds().width;
		float x = rand() % (int)(WINDOW_WIDTH - meteorWidth);
		float y = rand() % (int)(WINDOW_HEIGHT / 2) -
			WINDOW_HEIGHT / 2;
		sprite.setPosition(x, y);
		speedx = rand() % 5 - 2;
		speedy = rand() % 6 + 3;
	}

	void update() {
		sprite.move(speedx, speedy);
		sf::Vector2f pos = sprite.getPosition();
		float meteorWidth = sprite.getLocalBounds().width;
		if (pos.x < -meteorWidth || pos.y > WINDOW_HEIGHT ||
			pos.x > WINDOW_WIDTH)
		{
			spawn();
		}
	}

	sf::Sprite& getSprite() { return sprite; }

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }

	int getDamage() { return damage; }
};

std::string Meteor::mFileNames[] = { "big.png", "med.png", "small.png", "tiny.png" };

int Meteor::arrDamage[] = { 50,30,15,5 };