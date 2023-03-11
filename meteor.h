#pragma once
#include "settings.h"
#include "game.h"

class Meteor
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;
public:
	static std::string arr_met[];
	Meteor() 
	{
		int index = rand() % met_type_qty;
		texture.loadFromFile(arr_met[index]);
		sprite.setTexture(texture);
		speedy = rand() % 6 + 2;
		speedx = rand() % 5 - 2;
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float x = rand() % (int)(WINDOW_WIDTH - bounds.width);
		float y = -(rand() % (int)(WINDOW_HEIGHT - bounds.height) + bounds.height);
		sprite.setPosition(x, y);
	}
	update(){}

};
std::string Meteor::arr_met[] = { "meteor_big.png", "meteor_med.png", "meteor_small.png", "meteor_tiny.png" };