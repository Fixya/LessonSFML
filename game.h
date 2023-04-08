#pragma once
#include "settings.h"
#include "meteor.h"
#include "player.h"
#include <vector>
#include <list>
#include "Bonus.h"

class Game {
public:
	Game() {
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
		window.setFramerateLimit(FPS);
		meteorSprites.reserve(METEORS_QTY);
		for (int i = 0; i < METEORS_QTY; i++) {
			meteorSprites.push_back(new Meteor());
		}
	}

	void play() {
		while (window.isOpen() && player.isAlive()) {
			checkEvents();
			update();
			//if (player.getHp() <= 0) game_state = GAME_OVER;
			checkCollisions();
			draw();
		}
	}

private:
	sf::RenderWindow window;
	std::vector<Meteor*> meteorSprites;
	Player player;
	std::list<Bonus*> bonusSprites;

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	void update() {
		for (auto meteor : meteorSprites) {
			meteor->update();
		}
		player.update();
	}

	void checkCollisions() {
		sf::FloatRect playerBounds = player.getHitBox();
		auto laserSprites = player.getLasers();
		for (auto& meteor : meteorSprites) {
			sf::FloatRect meteorHitBox = meteor->getHitBox();
			if (meteorHitBox.intersects(playerBounds)) {
				meteor->spawn();
				player.receiveDamage(meteor->getDamage());
			}
			for (auto& laser : (*laserSprites))
			{
				sf::FloatRect laserHitBox = laser->getHitBox();
				if (laserHitBox.intersects(meteorHitBox))
				{
					meteor->spawn();
					laser->setHit();
					player.receivePoint(meteor->getPoint());
					int chance = rand() % BONUS_RANGE;
					if (chance < BONUS_CHANCE)
					{
						Bonus* bonus = new Bonus((Bonus::BonusType)0, meteor->getPosition());
						bonusSprites.push_back(bonus);
						sf::Vector2f posit = bonus->getPosition();
						sf::FloatRect bonusHitBox = bonus->getHitBox();
						if (bonusHitBox.intersects(playerBounds))
						{
							bonus->setDel();
						}
					}
				}
			}
		}
		(*laserSprites).remove_if([](Laser* laser) {return laser->isHited(); });
		(bonusSprites).remove_if([](Bonus* bonus) {return bonus->isToDel(); });

	}

	void draw() {
		window.clear();
		for (auto meteor : meteorSprites) {
			window.draw(meteor->getSprite());
		}
		player.draw(window);
		window.display();
	}
};
