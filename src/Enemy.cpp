#include "Enemy.hpp"
#include<iostream>

namespace game
{
    EnemyCircle::EnemyCircle() : Circle(20.f, sf::Color::Red) {}

    float EnemyCircle::m_growthRate = 4;

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
        float distance = sqrt(pow(getPosition().x - GetTarget().getPosition().x, 2) + pow(getPosition().y - GetTarget().getPosition().y, 2)) - (getRadius() + GetTarget().getRadius());
        return distance <= 0.f;
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
        EndGame(window);
        followPlayer();
        m_shape.setRadius(m_shape.getRadius() + m_growthRate * dt);
    }
}