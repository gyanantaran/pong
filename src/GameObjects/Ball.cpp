// Ball.cpp
#include "../../include/Ball.hpp"
#include "SFML/System/Vector2.hpp"

ball::ball() {
    shape_.setOrigin({radius_, radius_});
    shape_.setPosition(position_);
    shape_.setRadius(radius_);
    shape_.setFillColor(color_);
}

sf::Vector2f ball::get_position() const { return position_; }
sf::Vector2f ball::get_velocity() const { return velocity_; }

void ball::update(const float dt) {
    position_ += velocity_ * dt;
    shape_.setPosition(position_);
}

void ball::draw(sf::RenderWindow *win) const { win->draw(shape_); }

void ball::set_position(const sf::Vector2f pos) {
    position_ = pos;
    shape_.setPosition(pos);
}

void ball::set_velocity(const sf::Vector2f vel) { velocity_ = vel; }

float ball::get_radius() const { return radius_; }
void ball::set_radius(const float rad) { radius_ = rad; }

float ball::get_left_side() const { return get_position().x - get_radius(); }

float ball::get_right_side() const { return get_position().x + get_radius(); }

float ball::get_up_side() const { return get_position().y - get_radius(); }

float ball::get_down_side() const { return get_position().y + get_radius(); }

