#pragma once
#include "settings.h"

class Shield
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Shield(sf::Vector2f position)
	{
		texture.loadFromFile(SHIELD_EFFECT_BONUS_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(position);
	}

	void update(sf::Vector2f position) { sprite.setPosition(position); }

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};