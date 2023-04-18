#pragma once
#include <list>
#include "settings.h"
#include "laser.h"
#include "text.h"
#include "shield.h"

class Player {
public:
	Player();
	void fire();
	void update();
	void draw(sf::RenderWindow& window);
	sf::FloatRect getHitBox();
	int getHp();
	bool isAlive();
	void receivePoint(int points);
	void receiveDamage(int damage);
	std::list<Laser*>* getLasers();
	void activateMultiLaser();
	void deactivateMultiLaser();
	void activateHp();
	void deactivateHp();
	void activateShield();
	//void deactivateShield();
	sf::Vector2f getCenterPosition();
	bool shieldIsActive() { return shieldActive; }
	void deactivateShield() { shieldActive = false; }
	void decreaseShieldMargin();
	sf::FloatRect getShieldHitBox();
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx = 0.f;
	std::list<Laser*> lasers;
	sf::Clock timer;
	int hp = 100, point;
	TextObj hpText, pointText;
	sf::FloatRect bounds;
	bool multiLaser = false;
	bool Hp = false;
	int counter;
	Shield shield;
	bool shieldActive = false;
	int currTime, prevFireTime;
	int prevMultiLaserBonusTime; //,currMultiLaserBonusTime;
	int prevShieldTime; //currShieldTime;
	int shieldMargin = SHIELD_MARGIN;
};
//не пропускал метеориты и исчезал со временем

Player::Player() : hpText(std::to_string(hp), sf::Vector2f{ 0.f, 0.f }), pointText(std::to_string(point), sf::Vector2f{ WINDOW_WIDTH - 200.f, 0.f }),
shield(getCenterPosition())
{
	texture.loadFromFile(PLAYER_FILE_NAME);
	sprite.setTexture(texture);
	sprite.setPosition(PLAYER_START_POS);
	bounds = sprite.getGlobalBounds();
	timer.restart();
	prevFireTime = timer.getElapsedTime().asMilliseconds();
}

void Player::update() {
	currTime = timer.getElapsedTime().asMilliseconds();
	if (currTime - prevMultiLaserBonusTime > MULTI_LASER_BONUS_DURATION) multiLaser = false;
	if (shieldMargin <= 0) multiLaser = shieldActive;

	bounds = sprite.getLocalBounds();
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
	if (shieldIsActive()) {
		shield.setPosition(getCenterPosition());
	}else
		shield.setPosition(sf::Vector2f{ WINDOW_WIDTH/2, WINDOW_HEIGHT + 100.f });
}

void Player::draw(sf::RenderWindow& window) {
	if (shieldIsActive())
	{
		shield.draw(window);
	}
	for (auto laser : lasers) {
		window.draw(laser->getSprite());
	}
	window.draw(sprite);
	hpText.draw(window);
	pointText.draw(window);
}

void Player::fire() {
	{
		if (currTime - prevFireTime > FIRE_COOLDOWN) {
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
				prevFireTime = currTime;
			}
		}
	}
}

sf::FloatRect Player::getHitBox() { return sprite.getGlobalBounds(); }
int Player::getHp() { return hp; }
bool Player::isAlive() { return hp > 0; }
void Player::receivePoint(int points) { point += points; }
void Player::receiveDamage(int damage) { hp -= damage; }
std::list<Laser*>* Player::getLasers() { return &lasers; }
void Player::activateMultiLaser() 
{ 
	multiLaser = true;
	prevMultiLaserBonusTime = timer.getElapsedTime().asMilliseconds();
}
void Player::deactivateMultiLaser() { multiLaser = false; }
void Player::activateHp() { Hp = true; }
void Player::deactivateHp() { Hp = false; }
void Player::activateShield()
{ 
	shieldActive = true;
	shieldMargin = SHIELD_MARGIN;
	prevShieldTime = timer.getElapsedTime().asMilliseconds();
}
void Player::decreaseShieldMargin() { shieldMargin--; }
sf::Vector2f Player::getCenterPosition() { return sf::Vector2f{ sprite.getPosition().x + bounds.width / 2, sprite.getPosition().y + bounds.height / 2 }; }
sf::FloatRect Player::getShieldHitBox() { return shield.getHitBox(); }