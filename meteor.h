#pragma once
#include "settings.h"
#include "game.h"

class Meteor
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;
	void spawn()
	{
		speedy = rand() % 6 + 2;
		speedx = rand() % 5 - 2;
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float x = rand() % (int)(WINDOW_WIDTH - bounds.width);
		float y = -(rand() % (int)(WINDOW_HEIGHT - bounds.height) + bounds.height);
		sprite.setPosition(x, y);
	}
public:
	static std::string arr_met[];
	Meteor() 
	{
		int index = rand() % met_type_qty;
		texture.loadFromFile("meteor_" + arr_met[index]);
		sprite.setTexture(texture);
		spawn();
	}
	void update()
	{
		sprite.move(speedx, speedy);
		sf::Vector2f pos = sprite.getPosition();
		sf::FloatRect bounds = sprite.getGlobalBounds();
		if (bounds.left < -bounds.width || bounds.left > WINDOW_WIDTH || bounds.top > WINDOW_HEIGHT) spawn();
	}
	sf::Sprite getSprite() { return sprite; }
};
std::string Meteor::arr_met[] = { "big.png", "med.png", "small.png", "tiny.png" };