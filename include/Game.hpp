// Game.hpp
#pragma once

#include "Ball.hpp"
#include "Paddle.hpp"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/String.hpp"
#include "SFML/Window/VideoMode.hpp"

class Game {
public:
  Game();

  void run();

private:
  void handleEvents();
  void update(float deltaTime);
  void handleCollisions();
  void draw();

private:
  sf::VideoMode window_mode;
  sf::String window_title;
  sf::RenderWindow window;
  sf::Vector2f window_size = {800, 500};
  sf::Color window_background_color;

  Ball ball;
  Paddle left_paddle;
  Paddle right_paddle;

  sf::Clock game_clock;
};
