#pragma once
#include "settings.h"

class Shield
{
public:
	Shield(sf::Vector2f centerPosition);
	void draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f centerPosition);
	sf::FloatRect getHitBox();
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Clock timer;
	bool active = false;
};
Shield::Shield(sf::Vector2f position)
{
	texture.loadFromFile(SHIELD_EFFECT_BONUS_FILE_NAME);
	sprite.setTexture(texture);
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2, bounds.height / 2);
	sprite.setPosition(position);
}
void Shield::draw(sf::RenderWindow& window) { window.draw(sprite); }

void Shield::setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }

sf::FloatRect Shield::getHitBox() { return sprite.getGlobalBounds(); }