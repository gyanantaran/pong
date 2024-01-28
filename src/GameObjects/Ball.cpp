// Ball.cpp
#include "../../include/Ball.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Vector2.hpp"

Ball::Ball(const sf::Vector2f pos, const sf::Vector2f vel, const float rad,
           const sf::Color col)
    : position(pos), velocity(vel), radius(rad), color(col) {

  shape.setOrigin({radius, radius});
  shape.setPosition(position);
  shape.setRadius(radius);
  shape.setFillColor(color);
}

sf::Vector2f Ball::getPosition() const { return position; }
sf::Vector2f Ball::getVelocity() const { return velocity; }

void Ball::update(const float dt) {
  position += velocity * dt;
  shape.setPosition(position);
}

void Ball::draw(sf::RenderWindow *win) { win->draw(shape); }

void Ball::setPosition(sf::Vector2f pos) {
  position = pos;
  shape.setPosition(pos);
}

void Ball::setVelocity(sf::Vector2f vel) { velocity = vel; }
