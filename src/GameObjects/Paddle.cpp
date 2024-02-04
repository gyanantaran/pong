// Paddle.cpp
#include "../../include/Paddle.hpp"

paddle::paddle() {
    shape_.setOrigin({size_.x / 2, size_.y / 2});
    shape_.setPosition(position_);
    shape_.setSize(size_);
    shape_.setFillColor(color_);
}

sf::Vector2f paddle::get_position() const { return position_; }
sf::Vector2f paddle::get_velocity() const { return velocity_; }

void paddle::update(const float dt) {
    position_ += velocity_ * dt;
    shape_.setPosition(position_);
}

void paddle::draw(sf::RenderWindow *win) const { win->draw(shape_); };

void paddle::set_position(sf::Vector2f pos) {
    position_ = pos;
    shape_.setPosition(pos);
}

void paddle::set_velocity(const sf::Vector2f vel) { velocity_ = vel; }

sf::Vector2f paddle::get_size() const { return size_; }

float paddle::get_speed() const { return speed_; }

void paddle::set_speed(const float spee) { speed_ = spee; }

float paddle::get_left_side() const { return get_position().x - get_size().x / 2; }
float paddle::get_right_side() const { return get_position().x + get_size().x / 2; }
float paddle::get_up_side() const { return get_position().y - get_size().y / 2; }
float paddle::get_down_side() const { return get_position().y + get_size().y / 2; }
