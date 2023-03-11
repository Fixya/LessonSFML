#pragma once
#include "settings.h"
#include "player.h"

class Game
{
private:
	sf::RenderWindow window;
	void checkEvents()
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}
	void Update() {}
	void checkKollisions() {}
	void draw()
	{
		window.clear();
		window.display();
	}
public:
	Game()
	{
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
		window.setFramerateLimit(FPS);
	}
	void Play()
	{
		while (window.isOpen())
		{
			checkEvents();
			Update();
			checkKollisions();
			draw();
		}
	}
};