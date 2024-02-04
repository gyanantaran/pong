// Ball.hpp
#pragma once

#include "GameObject.hpp"
#include "SFML/Graphics/CircleShape.hpp"

class ball final : public game_object {
public:
    explicit ball();

    // getters and setters
    sf::Vector2f get_position() const override;

    sf::Vector2f get_velocity() const override;

    float get_radius() const;

    void set_position(sf::Vector2f pos) override;

    void set_velocity(sf::Vector2f vel) override;

    void set_radius(float rad);

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

    sf::CircleShape shape_;
    float radius_ = 30;
};
