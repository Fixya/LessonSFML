#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 1000;
const std::string WINDOW_TITLE = "Race to the bottom";
const float FPS = 60.f;

const std::string PLAYER_NAME_FILE = "player_blue.png";
const sf::Vector2f MeteorSize { WINDOW_WIDTH / 2, WINDOW_HEIGHT - 550 };
const float met_type_qty = 8;
//const sf::Vector2f START{ WINDOW_WIDTH / 2, WINDOW_HEIGHT - 550 };