#pragma once
#include "settings.h"

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Player() {}
	void update() {}
	sf::Sprite getSprite() { return sprite; }

};