// Ball.hpp
#pragma once

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"

// Forward declaration of Game class
class Game;

// sf::Vector2f PADDLE_SIZE = {20, 50};
// sf::Vector2f PADDLE_POSITION = {0, 0};
// sf::Vector2f PADDLE_VELOCITY = {0, 0};

class Paddle {
public:
  // Declare Game as a friend class
  friend class Game;

  Paddle(sf::Vector2f pos = {0, 0}, sf::Vector2f vel = {0, 0},
         sf::Vector2f siz = {20, 150}, sf::Color col = sf::Color::Black);

  sf::Vector2f getPosition() const;
  sf::Vector2f getVelocity() const;

private:
  sf::Color color;
  sf::Vector2f position;
  sf::Vector2f velocity;

  sf::RectangleShape shape;
  sf::Vector2f size;

  float key_speed = 10;

  void setPosition(sf::Vector2f pos);
  void setVelocity(sf::Vector2f vel);

  void update(float dt);
  void draw(sf::RenderWindow *win);
};
