#include "Player.hpp"
#include<iostream>
namespace game
{
    PlayerCircle::PlayerCircle() : Circle(30.f, sf::Color::Green) {}

    std::unique_ptr<PlayerCircle> PlayerCircle::instance = nullptr;

    PlayerCircle& PlayerCircle::getInstance()
    {
        if (instance == nullptr)
        {
            instance.reset(new PlayerCircle());
        }
        return *instance;
    }

    void PlayerCircle::update(sf::RenderWindow& window)
    {
        handleInput();
        PlayerWin(window);
    }

    void PlayerCircle::move(float x, float y) {
        m_shape.move(x, y);
    }

    void PlayerCircle::handleInput() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            move(-4.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            move(4.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            move(0.f, -4.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            move(0.f, 4.f);
        }
    }
    bool PlayerCircle::TimerIsOver()
    {
        if (clock.getElapsedTime().asSeconds() >= 15.f)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void PlayerCircle::PlayerWin(sf::RenderWindow& window)
    {
        if (TimerIsOver())
        {
            std::cout << "You win!" << std::endl;
            window.close();
        }
    }
}