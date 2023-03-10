#pragma once
#include "settings.h"
#include "game.h"

class Text_ob
{
private:
	sf::Font font;
	sf::Text text;
public:
	Text_ob(std::string str, sf::Vector2f pos)
	{
		font.loadFromFile(RES_SIZE + FONT_FILE_NAME);
		text.setString(str);
		text.setFont(font);
		text.setCharacterSize(CHAR_SIZE);
		text.setPosition(pos);
	}
	void update()
	{
		
	}
	sf::Text getText() { return text; }
};

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;
	int lives = 3;
public:
	Player() {
		texture.loadFromFile(PLAYER_NAME_FILE);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		sprite.setPosition((WINDOW_WIDTH - bounds.width) / 2, WINDOW_HEIGHT - bounds.height - 50.f);
	}
	void update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) speedy = -5;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) speedx = -10;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) speedy = 5;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) speedx = 10;
		sprite.move(speedx, speedy);
		speedx = 0.f;
		speedy = 0.f;
		if (sprite.getPosition().y <= 0)
			sprite.setPosition(sprite.getPosition().x, 0);
		if (sprite.getPosition().y + 100 >= WINDOW_HEIGHT)
			sprite.setPosition(sprite.getPosition().x, WINDOW_HEIGHT - 100);
		if (sprite.getPosition().x <= 0)
			sprite.setPosition(0, sprite.getPosition().y); 
		if (sprite.getPosition().x + 100 >= WINDOW_WIDTH)
			sprite.setPosition(WINDOW_WIDTH - 100, sprite.getPosition().y);
	}
	void incLives() { lives++; }
	void decLives() { lives--; }
	sf::Sprite getSprite() { return sprite; }
	int getLives() { return lives; }
};