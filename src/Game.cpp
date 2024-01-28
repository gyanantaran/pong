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
Game::Game() : ball(), left_paddle(), right_paddle() {
  // setting the defaults for the `GameObjects`
  ball.setPosition(window_size * (float)0.5);
  ball.setVelocity({100, 00});

  left_paddle.setPosition({0 + left_paddle.size.x, window_size.y * (float)0.5});
  left_paddle.setVelocity({0, 0});

  right_paddle.setPosition(
      {window_size.x - left_paddle.size.x, window_size.y * (float)0.5});
  right_paddle.setVelocity({0, 0});

  // setting the default `sf::RenderWindow` options
  window_mode = sf::VideoMode(window_size.x, window_size.y);
  window_title = "My window";
  window.create(window_mode, window_title);
  window_background_color = sf::Color::White;
}

// runs a game, the only public function
void Game::run() {
  while (window.isOpen()) {
    const float dt = game_clock.restart().asSeconds();
    handleEvents();
    update(dt);
    draw();
  }
}

// manages events
void Game::handleEvents() {
  sf::Event event{};
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::W) {
        left_paddle.position.y += -1 * left_paddle.key_speed;
      }
      if (event.key.code == sf::Keyboard::S) {
        left_paddle.position.y += 1 * left_paddle.key_speed;
      }
      if (event.key.code == sf::Keyboard::Up) {
        right_paddle.position.y += -1 * right_paddle.key_speed;
      }
      if (event.key.code == sf::Keyboard::Down) {
        right_paddle.position.y += 1 * right_paddle.key_speed;
      }
    }
  }
}

// updates the game state
void Game::update(const float deltaTime) {
  handleCollisions();

  // updating `GameObjects`
  ball.update(deltaTime);
  left_paddle.update(deltaTime);
  right_paddle.update(deltaTime);
}

// draws window
void Game::draw() {
  window.clear(window_background_color);

  // drawing `GameObjects`
  ball.draw(&window);
  left_paddle.draw(&window);
  right_paddle.draw(&window);

  // flipping the window
  window.display();
}

void Game::handleCollisions() {
  // Collision with walls

  // beyond vertical walls
  if ((ball.velocity.y > 0 && ball.position.y > window_size.y) ||
      (ball.velocity.y < 0 && ball.position.y < 0)) {
    ball.velocity.y *= -1;
  }

  // // beyond horizontal walls
  // if ((ball.velocity.x > 0 && ball.position.x > window_size.x) ||
  //     (ball.velocity.x < 0 && ball.position.x < 0)) {
  //   ball.velocity.x *= -1;
  // }

  // stopping paddles
  if (left_paddle.position.y < 0) {
    left_paddle.position.y = 0;
  }
  if (left_paddle.position.y > window_size.y) {
    left_paddle.position.y = window_size.y;
  }

  if (right_paddle.position.y < 0) {
    right_paddle.position.y = 0;
  }
  if (right_paddle.position.y > window_size.y) {
    right_paddle.position.y = window_size.y;
  }

  // collisions between ball and paddles
  if (ball.position.x < left_paddle.position.x + left_paddle.size.x / 2 &&
      ball.position.x > left_paddle.position.x - left_paddle.size.x / 2 &&
      ball.position.y < left_paddle.position.y + left_paddle.size.y / 2 &&
      ball.position.y > left_paddle.position.y - left_paddle.size.y / 2) {
    ball.velocity.x *= -1;
  }

  // collisions between ball and paddles
  if (ball.position.x < (right_paddle.position.x + right_paddle.size.x / 2) &&
      ball.position.x > (right_paddle.position.x - right_paddle.size.x / 2) &&
      ball.position.y < (right_paddle.position.y + right_paddle.size.y / 2) &&
      ball.position.y > (right_paddle.position.y - right_paddle.size.y / 2)) {
    ball.velocity.x *= -1;
  }
}
