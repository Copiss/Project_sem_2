#include "Enemy.hpp"
#include <iostream>
#include <random>
#include<SFML/Audio.hpp>

namespace game
{
    EnemyCircle::EnemyCircle() : Circle(20.f, sf::Color(250, 150, 190)) {}

    float EnemyCircle::m_growthRate = 4;

    void EnemyCircle::SetRandomPosition(EnemyCircle& enemy, sf::RenderWindow& window)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> xDist(0.f, static_cast<float>(window.getSize().x));
        std::uniform_real_distribution<float> yDist(0.f, static_cast<float>(window.getSize().y));
        enemy.move(xDist(gen), yDist(gen));
    }

    PlayerCircle& EnemyCircle::GetTarget()
    {
        static PlayerCircle& target = PlayerCircle::getInstance();
        return target;
    }

    void EnemyCircle::move(float x, float y)
    {
        m_shape.move(x, y);
    }

    void EnemyCircle::followPlayer() {
        if (GetTarget().getPosition().x > m_shape.getPosition().x) {
            move(1.f, 0.f);
        }
        if (GetTarget().getPosition().x < m_shape.getPosition().x) {
            move(-1.f, 0.f);
        }
        if (GetTarget().getPosition().y > m_shape.getPosition().y) {
            move(0.f, 1.f);
        }
        if (GetTarget().getPosition().y < m_shape.getPosition().y) {
            move(0.f, -1.f);
        }
    }

    bool EnemyCircle::checkCollision() const
    {
        return m_shape.getGlobalBounds().intersects(GetTarget().GetCircle().getGlobalBounds());
    }

    void EnemyCircle::EndCondition(sf::RenderWindow& window)
    {
        if (checkCollision())
        {
            // Воспроизвести звук
            try {

                PlayerCircle::SetGameStatus(true);
                LoseResult(window);

                sf::SoundBuffer buffer;
                if (!buffer.loadFromFile("Lose_sound.wav")) {
                    throw std::runtime_error("Failed to load sound file");
                }
                static sf::Sound sound(buffer);
                sound.setVolume(50);
                sound.play();
                sf::sleep(sf::seconds(2.0f));
                sound.stop();
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }

    void EnemyCircle::LoseResult(sf::RenderWindow& window)
    {
        // Загрузить текстуру
        try {
            sf::Texture texture;
            if (!texture.loadFromFile("You_lose.jpg")) {
                throw std::runtime_error("Failed to load texture file");
            }
            sf::Sprite sprite(texture);
            window.draw(sprite);
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void EnemyCircle::update(float dt, sf::RenderWindow& window)
    {
        followPlayer();
        m_shape.setRadius(m_shape.getRadius() + m_growthRate * dt);
    }
}