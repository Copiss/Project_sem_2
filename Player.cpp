#include "Player.hpp"

namespace game
{
    PlayerCircle::PlayerCircle() : Circle(30.f, sf::Color::Green) {}

    void PlayerCircle::move(float x, float y) {
        m_shape.move(x, y);
    }

    void PlayerCircle::handleInput() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            move(-0.1f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            move(0.1f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            move(0.f, -0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            move(0.f, 0.1f);
        }
    }
}