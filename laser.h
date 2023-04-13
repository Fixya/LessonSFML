﻿#pragma once
#include "settings.h"

class Laser {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedy;
	bool hit = false;
public:
	Laser(sf::Vector2f pos) {
		texture.loadFromFile(LASER_FILE_NAME);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(pos);
		speedy = -15.f;
	}

	void update() {
		sprite.move(0.f, speedy);
	}

	sf::Sprite& getSprite() { return sprite; }

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }

	void setHit() { hit = true; }
	bool isHited() { return hit; }

	bool offScreen() {
		if (sprite.getPosition().y > WINDOW_HEIGHT) return true;
		else return false;
	}
};