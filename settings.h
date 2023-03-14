#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 1000;
const float WINDOW_HEIGHT = 1000;
const std::string WINDOW_TITLE = "Space Travel";
const float FPS = 60.f;

const std::string PLAYER_NAME_FILE = "player_blue.png";
const sf::Vector2f MeteorSize { WINDOW_WIDTH / 2, WINDOW_HEIGHT - 550 };
const int met_type_qty = 4;
const size_t Meteor_QTY = 50;

const std::string RES_SIZE = "res\\";
const std::string FONT_FILE_NAME = "DS-DIGIB.ttf";
const size_t CHAR_SIZE = 32;

const float RECT_WIDTH = 250.f;
const float RECT_HEIGHT = 15.f;
const sf::Color RECT_COLOR{ sf::Color(0, 0, 0) };
const sf::Vector2f RECT_POS{ 0, 0 };