#pragma once
#include <list>
#include "settings.h"
#include "laser.h"
#include "text.h"
#include "shield.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx = 0.f;
	std::list<Laser*> lasers;
	sf::Clock timer;
	int hp, point;
	TextObj hpText, pointText;
	sf::FloatRect bounds;
	bool multiLaser = false;
	bool Hp = false;
	bool shield = false;
	int counter;
public:
	Player() : hpText(std::to_string(hp), sf::Vector2f{ 0.f, 0.f }), pointText(std::to_string(point), sf::Vector2f{ WINDOW_WIDTH - 200.f, 0.f })
	{
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(PLAYER_START_POS);
		bounds = sprite.getGlobalBounds();
		timer.restart();
		hp = 100;
		counter = 0;
		Shield::Shield(sprite.getPosition());
	}

	void fire() {
		{
			int now = timer.getElapsedTime().asMilliseconds();
			if (now > FIRE_COOLDOWN) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					sf::Vector2f pos = { sprite.getPosition().x + bounds.width / 2, sprite.getPosition().y };
					Laser* l = new Laser(pos);
					lasers.push_back(l);
					if (multiLaser)
					{
						sf::Vector2f leftPos = { sprite.getPosition().x, sprite.getPosition().y + bounds.width / 2 };
						Laser* leftL = new Laser(leftPos);
						lasers.push_back(leftL);
						sf::Vector2f rightPos = { sprite.getPosition().x + bounds.width, sprite.getPosition().y + bounds.width / 2 };
						Laser* rightL = new Laser(rightPos);
						lasers.push_back(rightL);
						counter++;
					}
					timer.restart();
				}
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
		if (Hp) {
			hp += 50;
			if (hp > 100) hp = 100;
			deactivateHp();
		}
		hpText.update("HP: " + std::to_string(hp));
		pointText.update("Points: " + std::to_string(point));
		if (counter >= 20) {
			counter = 0;
			deactivateMultiLaser();
		}
		if (shield)
		{
			//shield->update(sprite.getPosition());
		}
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

	void receivePoint(int points) { point += points; }

	void receiveDamage(int damage) { hp -= damage; }

	std::list<Laser*>* getLasers() { return &lasers; }

	void activateMultiLaser() { multiLaser = true; }
	void deactivateMultiLaser() { multiLaser = false; }
	void activateHp() { Hp = true; }
	void deactivateHp() { Hp = false; }
	void activateShield() { shield = true; }
	void deactivateShield() { shield = false; }
};