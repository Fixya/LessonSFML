#pragma once
#include "settings.h"

class Meteor {
public:
	static std::string mFileNames[];
	static int arrDamage[];
	static int arrPoint[];
	Meteor();
	void spawn();
	void update();
	sf::Sprite& getSprite();
	sf::FloatRect getHitBox();
	int getDamage();
	int getPoint();
	sf::Vector2f getPosition();
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;
	int damage, point;
};
Meteor::Meteor() {
	int index = rand() % 4;
	damage = arrDamage[index];
	point = arrPoint[index];
	texture.loadFromFile(IMAGES_FOLDER + mFileNames[index]);
	sprite.setTexture(texture);
	spawn();
}

void Meteor::spawn() {
	float meteorWidth = sprite.getLocalBounds().width;
	float x = rand() % (int)(WINDOW_WIDTH - meteorWidth);
	float y = rand() % (int)(WINDOW_HEIGHT / 2) -
		WINDOW_HEIGHT / 2;
	sprite.setPosition(x, y);
	speedx = rand() % 5 - 2;
	speedy = rand() % 6 + 3;
}

void Meteor::update() {
	sprite.move(speedx, speedy);
	sf::Vector2f pos = sprite.getPosition();
	float meteorWidth = sprite.getLocalBounds().width;
	if (pos.x < -meteorWidth || pos.y > WINDOW_HEIGHT ||
		pos.x > WINDOW_WIDTH)
	{
		spawn();
	}
}

sf::Sprite& Meteor::getSprite() { return sprite; }
sf::FloatRect Meteor::getHitBox() { return sprite.getGlobalBounds(); }
int Meteor::getDamage() { return damage; }
int Meteor::getPoint() { return point; }
sf::Vector2f Meteor::getPosition() { return sprite.getPosition(); }

std::string Meteor::mFileNames[] = { "big.png", "med.png", "small.png", "tiny.png" };

int Meteor::arrDamage[] = { 50,30,15,5 };
int Meteor::arrPoint[] = { 15,10,5,1 };