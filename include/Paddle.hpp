// Paddle.hpp
#pragma once

#include "GameObject.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class paddle final : public game_object {
public:
    paddle();

    // getters and setters
    sf::Vector2f get_position() const override;

    sf::Vector2f get_velocity() const override;

    void set_position(sf::Vector2f pos) override;

    void set_velocity(sf::Vector2f vel) override;

    sf::Vector2f get_size() const;

    void set_size(sf::Vector2f siz);

    float get_speed() const;

    void set_speed(float spee);

    float get_left_side() const;
    float get_down_side() const;
    float get_up_side() const;
    float get_right_side() const;

    // update and draw
    void update(float dt) override;

    void draw(sf::RenderWindow *win) const override;

private:
    sf::Vector2f position_ = {0, 0};
    sf::Vector2f velocity_ = {0, 0};
    sf::Color color_ = sf::Color::Black;

    sf::RectangleShape shape_;
    sf::Vector2f size_ = {20, 150};

    float speed_ = 100;
};
