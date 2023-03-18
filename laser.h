#pragma once
#include "game.h"
#include "player.h"
#include "settings.h"

class Laser
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedy;
public:
	Laser(sf::Vector2f pos)
	{
		texture.loadFromFile(LASER_NAME_FILE);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition((WINDOW_WIDTH - bounds.width) / 2 - 50.f, WINDOW_HEIGHT - bounds.height - 50.f);
		speedy = -15.f;
	};
	void upbate()
	{
		sprite.move(0.f, speedy);
	}
	sf::Sprite& getSprite() { return sprite; }
};