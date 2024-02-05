// Game.hpp
#pragma once

#include "Ball.hpp"
#include "Paddle.hpp"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/String.hpp"
#include "SFML/Window/VideoMode.hpp"

class game {
public:
    game();

    void run();

private:
    void handle_events();

    void update(float delta_time);

    void handle_collisions();

    void draw();

    sf::Vector2u get_window_center() const;

    sf::Vector2u get_window_left_side() const;
    sf::Vector2u get_window_right_side() const;
    sf::Vector2u get_window_up_side() const;
    sf::Vector2u get_window_down_side() const;

    sf::VideoMode window_mode_;
    sf::String window_title_;
    sf::RenderWindow window_;
    sf::Vector2u window_size_ = {800, 500};
    sf::Color window_background_color_;

    ball ball_;
    paddle left_paddle_;
    paddle right_paddle_;

    sf::Clock game_clock_;
};
