// Game.cpp
#include "../include/Game.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"

/*
    Game
This class represents the controller for a "game"
This class is responsible for
*/
game::game() : ball_(), left_paddle_(), right_paddle_() {
    // defaults for `GameObjects`
    ball_.set_position(sf::Vector2f(get_window_center()));
    ball_.set_velocity({-100, -100});

    left_paddle_.set_position(sf::Vector2f(get_window_left_side()) + sf::Vector2f{left_paddle_.get_size().x, 0});
    left_paddle_.set_velocity({0, 0});

    right_paddle_.set_position(sf::Vector2f(get_window_right_side()) - sf::Vector2f({right_paddle_.get_size().x, 0}));
    right_paddle_.set_velocity({0, 0});


    // setting the default `sf::RenderWindow` options
    window_mode_ = sf::VideoMode(window_size_.x, window_size_.y);
    window_title_ = "My window";
    window_.create(window_mode_, window_title_);
    window_background_color_ = sf::Color::White;
}


// runs a game
void game::run() {
    while (window_.isOpen()) {
        const float dt = game_clock_.restart().asSeconds();
        handle_events();
        update(dt);
        draw();
    }
}


// manages events
void game::handle_events() {
    sf::Event event{};
    while (window_.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window_.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.scancode) {
                    case sf::Keyboard::Scan::Scancode::Up:
                        right_paddle_.set_velocity({right_paddle_.get_velocity().x, -1 * right_paddle_.get_speed()});
                        break;
                    case sf::Keyboard::Scan::Scancode::Down:
                        right_paddle_.set_velocity({right_paddle_.get_velocity().x, 1 * right_paddle_.get_speed()});
                        break;
                    case sf::Keyboard::Scan::Scancode::W:
                        left_paddle_.set_velocity({left_paddle_.get_velocity().x, -1 * left_paddle_.get_speed()});
                        break;
                    case sf::Keyboard::Scan::Scancode::S:
                        left_paddle_.set_velocity({left_paddle_.get_velocity().x, 1 * left_paddle_.get_speed()});
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::KeyReleased:
                break;
            default:;
                break;
        }
    }
}


// updates the game state
void game::update(const float delta_time) {
    handle_collisions();

    // updating `GameObjects`
    ball_.update(delta_time);
    left_paddle_.update(delta_time);
    right_paddle_.update(delta_time);
}


// draws window
void game::draw() {
    window_.clear(window_background_color_);

    // drawing `GameObjects`
    ball_.draw(&window_);
    left_paddle_.draw(&window_);
    right_paddle_.draw(&window_);

    // flipping the window
    window_.display();
}


// handles collisions
void game::handle_collisions() {
    // Ball-Collision with walls
    // beyond up and down walls
    if (ball_.get_velocity().y > 0 && ball_.get_down_side() > get_window_down_side().y) {
        ball_.set_position({ball_.get_position().x, window_size_.y - ball_.get_radius()});
        ball_.set_velocity({ball_.get_velocity().x, -1 * ball_.get_velocity().y});
    } else if (ball_.get_velocity().y < 0 && ball_.get_up_side() < 0) {
        // ball_.set_position({ball_.get_position().x, 0 + ball_.get_radius()});
        ball_.set_velocity({ball_.get_velocity().x, -1 * ball_.get_velocity().y});
    }

    // beyond horizontal walls
    if (ball_.get_velocity().x > 0 && ball_.get_right_side() > window_size_.x) {
        ball_.set_position({window_size_.x - ball_.get_radius(), ball_.get_position().y});
        ball_.set_velocity({-1 * ball_.get_velocity().x, ball_.get_velocity().y});
    } else if (ball_.get_velocity().x < 0 && ball_.get_left_side() < 0) {
        ball_.set_position({0 + ball_.get_radius(), ball_.get_position().y});
        ball_.set_velocity({-1 * ball_.get_velocity().x, ball_.get_velocity().y});
    }

    // paddle collision with window edges
    // up side of the left paddle with the up side of the window
    if (left_paddle_.get_up_side() < 0) {
        left_paddle_.set_position({left_paddle_.get_position().x, left_paddle_.get_size().y / 2});
        if (left_paddle_.get_velocity().y < 0)
            left_paddle_.set_velocity({left_paddle_.get_velocity().x, 0});
    }

    // down side of the left paddle with the down side of the window
    if (left_paddle_.get_down_side() > window_size_.y) {
        left_paddle_.set_position({left_paddle_.get_position().x, window_size_.y - left_paddle_.get_size().y / 2});
        if (left_paddle_.get_velocity().y > 0)
            left_paddle_.set_velocity({left_paddle_.get_velocity().x, 0});
    }

    // up side of the right paddle with the up side of the window
    if (right_paddle_.get_up_side() < 0) {
        right_paddle_.set_position({right_paddle_.get_position().x, right_paddle_.get_size().y / 2});
        if (right_paddle_.get_velocity().y < 0)
            right_paddle_.set_velocity({right_paddle_.get_velocity().x, 0});
    }

    // down side of the right paddle with the down side of the window
    if (right_paddle_.get_down_side() > window_size_.y) {
        right_paddle_.set_position({right_paddle_.get_position().x, window_size_.y - right_paddle_.get_size().y / 2});
        if (right_paddle_.get_velocity().y > 0)
            right_paddle_.set_velocity({right_paddle_.get_velocity().x, 0});
    }

    // left side of the ball with the right side of the left paddle
    if ((ball_.get_left_side() < left_paddle_.get_right_side()) &&
        ((ball_.get_down_side() > left_paddle_.get_up_side()) &&
         (ball_.get_up_side() < left_paddle_.get_down_side()))) {
        ball_.set_velocity({-1 * ball_.get_velocity().x, ball_.get_velocity().y});
    }

    // right side of the ball with the left side of the right paddle
    if ((ball_.get_right_side() > right_paddle_.get_left_side()) &&
        ((ball_.get_down_side() > right_paddle_.get_up_side()) &&
         (ball_.get_up_side() < right_paddle_.get_down_side()))) {
        ball_.set_velocity({-1 * ball_.get_velocity().x, ball_.get_velocity().y});
    }
}

sf::Vector2u game::get_window_center() const { return {window_size_.x / 2, window_size_.y / 2}; }

sf::Vector2u game::get_window_left_side() const { return {0, window_size_.y / 2}; }
sf::Vector2u game::get_window_right_side() const { return {window_size_.x, window_size_.y / 2}; }
sf::Vector2u game::get_window_down_side() const { return {window_size_.x / 2, window_size_.y}; }
sf::Vector2u game::get_window_up_side() const { return {window_size_.x / 2, 0}; }
