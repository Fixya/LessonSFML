#pragma once
#include "settings.h"

class Laser {
public:
	Laser(sf::Vector2f pos);
	void update();
	sf::Sprite& getSprite();
	sf::FloatRect getHitBox();
	void setHit();
	bool isHited();
	bool offScreen();
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedy;
	bool hit = false;
};
Laser::Laser(sf::Vector2f pos) {
	texture.loadFromFile(LASER_FILE_NAME);
	sprite.setTexture(texture);
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2, bounds.height / 2);
	sprite.setPosition(pos);
	speedy = -15.f;
}

void Laser::update() {
	sprite.move(0.f, speedy);
}

sf::Sprite& Laser::getSprite() { return sprite; }

sf::FloatRect Laser::getHitBox() { return sprite.getGlobalBounds(); }

void Laser::setHit() { hit = true; }
bool Laser::isHited() { return hit; }

bool Laser::offScreen() {
	if (sprite.getPosition().y > WINDOW_HEIGHT) return true;
	else return false;
}