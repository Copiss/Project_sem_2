#include "Enemy.hpp"
#include<iostream>

namespace game
{
    EnemyCircle::EnemyCircle() : Circle(20.f, sf::Color::Red) {}

    void EnemyCircle::move(float x, float y) {
        m_shape.move(x, y);
    }
    float EnemyCircle::m_growthRate = 18;
    PlayerCircle& EnemyCircle::target = PlayerCircle::getInstance();

    void EnemyCircle::followPlayer() {
        if (target.getPosition().x > m_shape.getPosition().x) {
            move(0.01f, 0.f);
        }
        if (target.getPosition().x < m_shape.getPosition().x) {
            move(-0.01f, 0.f);
        }
        if (target.getPosition().y > m_shape.getPosition().y) {
            move(0.f, 0.01f);
        }
        if (target.getPosition().y < m_shape.getPosition().y) {
            move(0.f, -0.01f);
        }
    }

    bool EnemyCircle::checkCollision()
    {
        return m_shape.getGlobalBounds().intersects(target.GetCircle().getGlobalBounds());
    }

    void EnemyCircle::EndGame(sf::RenderWindow& window)
    {
        if (checkCollision())
        {
            std::cout << "Game Over!" << std::endl;
            window.close();
        }
    }
    

    void EnemyCircle::update(float dt, sf::RenderWindow& window)
    {
        m_shape.setRadius(m_shape.getRadius() + m_growthRate * dt);
        followPlayer();
        EndGame(window);
    }
}