#pragma once
#include "settings.h" 
#include <vector> 
#include "player.h"
#include "meteor.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	std::vector<Meteor*> meteorSprites;
	Text_ob lives;
	sf::RectangleShape rect;
public:
	void spawnMeteors(size_t n) {
		for (int i = 0; i < n; i++)
		{
			int num = rand() % 4 + 1;
			Meteor* m = new Meteor();
			meteorSprites.push_back(m);
		}
	}

	Game() : lives(std::to_string(player.getLives()), sf::Vector2f { WINDOW_WIDTH/2, 0.f })
	{
		window.create(sf::VideoMode{ (size_t)WINDOW_WIDTH, (size_t)WINDOW_HEIGHT }, WINDOW_TITLE);
		window.setFramerateLimit(FPS);
		meteorSprites.reserve(Meteor_QTY);
		spawnMeteors(Meteor_QTY);
		rect.setSize(sf::Vector2f(RECT_WIDTH, RECT_HEIGHT));
		rect.setFillColor(RECT_COLOR);
		rect.setPosition(RECT_POS);
	}

	

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}

	void update() {
		player.update();
		for (auto m : meteorSprites) m ->update();
		lives.update(std::to_string(player.getLives));
	}

	void checkCollisions() {}

	void draw() {
		window.clear();
		for (auto m : meteorSprites) window.draw(m->getSprite());
		window.draw(player.getSprite());
		window.draw(lives.getText);
		window.display();
	}

	void play() {
		while (window.isOpen()) {
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}
};