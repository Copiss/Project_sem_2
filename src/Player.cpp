#include "Player.hpp"

namespace game
{
    PlayerCircle::PlayerCircle() : Circle(40.f, sf::Color::Green) {}

    std::unique_ptr<PlayerCircle> PlayerCircle::instance = nullptr;

    PlayerCircle& PlayerCircle::getInstance() 
    {
        if (instance == nullptr)
        {
            instance.reset(new PlayerCircle);
        }
        return *instance;
    }

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
    void PlayerCircle::update()
    {
        handleInput();
    }
}