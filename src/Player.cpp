#include "Player.hpp"
#include<iostream>
namespace game
{
    PlayerCircle::PlayerCircle() : Circle(30.f, sf::Color::Green) {}

    std::unique_ptr<PlayerCircle> PlayerCircle::instance = nullptr;

    bool PlayerCircle::endGame = false;

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
    
    bool PlayerCircle::Getter()
    {
        return endGame;
    }
    void PlayerCircle::Setter(bool n)
    {
         endGame = n;
    }
    void PlayerCircle::PlayerWin(sf::RenderWindow& window, Timer& t)
    {
        
        if (t.TimerIsOver())
        {
            Setter(true);
            sf::Texture texture;
            texture.loadFromFile("You_win.jpg");
            sf::Sprite sprite(texture);
            window.draw(sprite);
        }
    }
}