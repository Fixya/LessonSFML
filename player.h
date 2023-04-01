#pragma once
#include <list>
#include "settings.h"
#include "laser.h"
#include "text.h"

class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speedx;
	std::list<Laser*> lasers;
	sf::Clock timer;
	int hp, point;
	TextObj hpText, pointText;
	sf::FloatRect bounds;
public:
	Player() : hpText(std::to_string(hp), sf::Vector2f{ 0.f, 0.f }), pointText(std::to_string(point), sf::Vector2f{ WINDOW_WIDTH - 200.f, 0.f })
	{
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(PLAYER_START_POS);
		bounds = sprite.getGlobalBounds();
		speedx = 0.f;
		timer.restart();
		hp = 100;
	}

	void fire() {
		int now = timer.getElapsedTime().asMilliseconds();
		if (now > FIRE_COOLDOWN) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				sf::Vector2f pos = { sprite.getPosition().x + bounds.width / 2, sprite.getPosition().y };
				Laser* l = new Laser(pos);
				lasers.push_back(l);
				timer.restart();
			}
		}
	}

	void update() {
		speedx = 0.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			speedx = -PLAYER_SPEED;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			speedx = PLAYER_SPEED;
		}
		sprite.move(speedx, 0.f);
		fire();
		for (auto laser : lasers) {
			laser->update();
		}
		hpText.update("HP: " + std::to_string(hp));
		pointText.update("Points: " + std::to_string(point));
	}

	void draw(sf::RenderWindow& window) {
		for (auto laser : lasers) {
			window.draw(laser->getSprite());
		}
		window.draw(sprite);
		hpText.draw(window);
		pointText.draw(window);
	}

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }

	int getHp() { return hp; }

	bool isAlive() { return hp > 0; }

	void receivePoint(int damage) { point += damage;}

	void receiveDamage(int damage) { hp -= damage; }

	std::list<Laser*>* getLasers() { return &lasers; }
};