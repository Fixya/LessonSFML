#pragma once
#include "settings.h"

class Bonus {
public:
	enum BonusType { MULTI_LASER, HP, SHIELD, BONUSES_TYPE_QTY };
	Bonus(BonusType type, sf::Vector2f position);
	void update();
	void draw(sf::RenderWindow& window);
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
	void setDel();
	bool isToDel();
	bool offScreen();
	void act(Player& player);
	void effect(sf::Vector2f position);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	BonusType type;
	bool del = false;
};
Bonus::Bonus(BonusType type, sf::Vector2f position)
{
	switch (type)
	{
	case MULTI_LASER:
		this->type = type;
		texture.loadFromFile(MULTI_LASER_BONUS_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(position);
		break;
	case HP:
		this->type = type;
		texture.loadFromFile(HP_UP_BONUS_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(position);
		break;
	case SHIELD:
		this->type = type;
		texture.loadFromFile(SHIELD_UP_BONUS_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(position);
		break;
	}
}

void Bonus::update() { sprite.move(0.f, BONUS_SPEED); }

/*void Bonus::effect(sf::Vector2f position)
{
	texture.loadFromFile(SHIELD_EFFECT_BONUS_FILE_NAME);
	sprite.setTexture(texture);
	sprite.setPosition(position);
}*/

void Bonus::draw(sf::RenderWindow& window) { window.draw(sprite); }

sf::FloatRect Bonus::getHitBox() { return sprite.getGlobalBounds(); }

sf::Vector2f Bonus::getPosition() { return sprite.getPosition(); }

bool Bonus::isToDel() { return del; }
void Bonus::setDel() { del = true; }
bool Bonus::offScreen() {
	if (sprite.getPosition().y > WINDOW_HEIGHT) return true;
	else return false;
}
void Bonus::act(Player& player)
{
	switch (type)
	{
	case MULTI_LASER:
		player.activateMultiLaser();
		break;
	case HP:
		player.activateHp();
		break;
	case SHIELD:
		player.activateShield();
		break;
	}
}