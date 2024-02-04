// GameObject.hpp
#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"

class game_object {
public:
    virtual ~game_object() = default;

    // update and draw
    virtual void update(float dt) = 0;

    virtual void draw(sf::RenderWindow* win) const = 0;

    // setters and getters
    [[nodiscard]] virtual sf::Vector2f get_position() const = 0;

    [[nodiscard]] virtual sf::Vector2f get_velocity() const = 0;

    virtual void set_position(sf::Vector2f pos) = 0;

    virtual void set_velocity(sf::Vector2f vel) = 0;

private:
    sf::Vector2f position_ = {0, 0};
    sf::Vector2f velocity_ = {0, 0};
    sf::Color color_ = sf::Color::Black;
};
