// Ball.hpp
#pragma once

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"

// Forward declaration of Game class
class Game;

// float BALL_RADIUS = 30;
// sf::Vector2f BALL_POSITION = {0, 0};
// sf::Vector2f BALL_VELOCITY = {0, 0};

class Ball {
public:
  // Declare Game as a friend class
  friend class Game;

  Ball(sf::Vector2f pos = {0, 0}, sf::Vector2f vel = {0, 0}, float rad = 30,
       sf::Color col = sf::Color::Black);

  sf::Vector2f getPosition() const;
  sf::Vector2f getVelocity() const;

private:
  sf::Vector2f position;
  sf::Vector2f velocity;

  sf::CircleShape shape;

  float radius;
  sf::Color color;

  void setPosition(sf::Vector2f pos);
  void setVelocity(sf::Vector2f vel);

  void update(float dt);
  void draw(sf::RenderWindow *win);
};
