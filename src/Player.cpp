#include "Player.hpp"
#include<iostream>
#include<SFML/Audio.hpp>

namespace game
{
    PlayerCircle::PlayerCircle() : Circle(30.f, sf::Color(215, 144, 245)) {}

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

    void PlayerCircle::update()
    {
        handleInput();
    }

    void PlayerCircle::move(float x, float y) {
        // Получить размеры окна
        sf::Vector2u windowSize = sf::Vector2u(1080, 710);

        // Получить текущую позицию круга
        sf::Vector2f pos = m_shape.getPosition();

        // Вычислить новые координаты круга
        float newX = pos.x + x;
        float newY = pos.y + y;

        // Проверить, находится ли круг в пределах окна
        if (newX - getRadius() >= -1.f * getRadius() && newX + m_shape.getRadius() <= windowSize.x - getRadius() &&
            newY - getRadius() >= -1.f * getRadius() && newY + m_shape.getRadius() <= windowSize.y - getRadius()) 
        {
            // Круг в пределах окна, переместить его
            m_shape.move(x, y);
        }
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
    
    bool PlayerCircle::GetGameStatus()
    {
        return endGame;
    }
    void PlayerCircle::SetGameStatus(bool n)
    {
         endGame = n;
    }
    void PlayerCircle::WinResult(sf::RenderWindow& window)
    {
        // Загрузить текстуру
        try {
            sf::Texture texture;
            if (!texture.loadFromFile("You_win.jpg")) {
                throw std::runtime_error("Failed to load texture file");
            }
            sf::Sprite sprite(texture);
            window.draw(sprite);
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    void PlayerCircle::PlayerWin(sf::RenderWindow& window, Timer& t)
    {
        
        if (t.TimerIsOver())
        {
            SetGameStatus(true);
            WinResult(window);

            // Воспроизвести звук
            try {
                sf::SoundBuffer buffer;
                if (!buffer.loadFromFile("Win_sound.wav")) {
                    throw std::runtime_error("Failed to load sound file");
                }
                sf::Sound sound(buffer);
                sound.play();
                sf::sleep(sf::seconds(1.5f)); // тут нужно в зависимости от размера звука указать
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
}