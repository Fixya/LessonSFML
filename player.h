#pragma once
#include "settings.h"
#include "game.h"

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float angle;
	float speedx, speedy;
	float speed;
public:
	Player() {
		texture.loadFromFile(PLAYER_NAME_FILE);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		//sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition((WINDOW_WIDTH - bounds.width) / 2, WINDOW_HEIGHT - bounds.height - 50.f);
		/*angle = 0;
		speed = 0;*/
	}
	void update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) speedy = -5;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) speedx = -10;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) speedy = 5;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) speedx = 10;
		sprite.move(speedx, speedy);
		speedx = 0.f;
		speedy = 0.f;
		if (sprite.getPosition().y <= 0 || sprite.getPosition().y >= WINDOW_HEIGHT)
			sprite.setPosition(sprite.getPosition().x, 0);
		if (sprite.getPosition().y + 40 >= WINDOW_HEIGHT || sprite.getPosition().y >= WINDOW_HEIGHT)
			sprite.setPosition(sprite.getPosition().x, WINDOW_HEIGHT - 40);
		if (sprite.getPosition().x <= 10 || sprite.getPosition().x >= WINDOW_WIDTH)
			sprite.setPosition(10, sprite.getPosition().y);
		if (sprite.getPosition().x + 10 >= WINDOW_WIDTH - 40 || sprite.getPosition().x >= WINDOW_WIDTH - 40)
			sprite.setPosition(WINDOW_WIDTH, sprite.getPosition().y);
	}
	sf::Sprite getSprite() { return sprite; }
};