// Paddle.cpp
#include "../../include/Paddle.hpp"
#include "SFML/System/Vector2.hpp"

Paddle::Paddle(const sf::Vector2f pos, const sf::Vector2f vel, sf::Vector2f siz,
               const sf::Color col)
    : position(pos), velocity(vel), size(siz), color(col) {

  shape.setOrigin({size.x / 2, size.y / 2});
  shape.setPosition(position);
  shape.setSize(size);
  shape.setFillColor(color);
}

sf::Vector2f Paddle::getPosition() const { return position; }
sf::Vector2f Paddle::getVelocity() const { return velocity; }

void Paddle::update(const float dt) {
  position += velocity * dt;
  shape.setPosition(position);
}

void Paddle::draw(sf::RenderWindow *win) { win->draw(shape); };

void Paddle::setPosition(sf::Vector2f pos) {
  position = pos;
  shape.setPosition(pos);
}

void Paddle::setVelocity(sf::Vector2f vel) { velocity = vel; }
