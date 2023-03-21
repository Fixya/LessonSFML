#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 1000;
const float WINDOW_HEIGHT = 1000;
const std::string WINDOW_TITLE = "Space Travel";
const float FPS = 60.f;

const std::string LASER_FILE_NAME = "laser.png";
const std::string PLAYER_FILE_NAME = "player_blue.png";
const sf::Vector2f MeteorSize{ WINDOW_WIDTH / 2, WINDOW_HEIGHT - 550 };
const int METEOR_TYPES_QTY = 4;
const size_t METEOR_QTY = 50;
const float PLAYER_SPEED = 10.f;

const std::string RES_FOLDER = "res\\";
const std::string IMAGES_FOLDER = "meteor_";
const std::string FONT_FILE_NAME = "DS-DIGIB.ttf";
const size_t CHAR_SIZE = 32;

const float RECT_WIDTH = 250.f;
const float RECT_HEIGHT = 15.f;
const sf::Color RECT_COLOR{ sf::Color(0, 0, 0) };
const sf::Vector2f RECT_POS{ 0, 0 };