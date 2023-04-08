#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 1000;
const float WINDOW_HEIGHT = 1000;
const std::string WINDOW_TITLE = "Space Travel";
const float FPS = 60.f;

const std::string LASER_FILE_NAME = "laser.png";
const std::string PLAYER_FILE_NAME = "player_blue.png";
const sf::Vector2f PLAYER_START_POS{ WINDOW_WIDTH / 2, WINDOW_HEIGHT - 200 };
const float PLAYER_SPEED = 10.f;

const sf::Vector2f MeteorSize{ WINDOW_WIDTH / 2, WINDOW_HEIGHT - 550 };
const int METEOR_TYPES_QTY = 4;
const int METEORS_QTY{ 20 };

const std::string IMAGES_FOLDER = "meteor_";
const std::string FONT_FILE_NAME = "DS-DIGIB.ttf";
const int FONT_SIZE = 32;

const float RECT_WIDTH = 250.f;
const float RECT_HEIGHT = 15.f;
const sf::Color RECT_COLOR{ sf::Color(0, 0, 0) };
const sf::Vector2f RECT_POS{ 0, 0 };

const int FIRE_COOLDOWN = 200;

const std::string MULTI_LASER_BONUS_FILE_NAME = "things_silver.png";
const std::string HP_UP_BONUS_FILE_NAME = "pill_green.png";
const std::string SHIELD_UP_BONUS_FILE_NAME = "shield_silver.png";
const float BONUS_SPEED = 10.f;
const int BONUS_RANGE = 10000;
const int BONUS_CHANCE = 500;