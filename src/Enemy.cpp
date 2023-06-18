#include "Enemy.hpp"

namespace game
{
    EnemyCircle::EnemyCircle() : Circle(20.f, sf::Color::Red) {}

    void EnemyCircle::move(float x, float y) {
        m_shape.move(x, y);
    }

    void EnemyCircle::followPlayer(const Circle& player) {
        if (player.getPosition().x > m_shape.getPosition().x) {
            move(0.01f, 0.f);
        }
        if (player.getPosition().x < m_shape.getPosition().x) {
            move(-0.01f, 0.f);
        }
        if (player.getPosition().y > m_shape.getPosition().y) {
            move(0.f, 0.01f);
        }
        if (player.getPosition().y < m_shape.getPosition().y) {
            move(0.f, -0.01f);
        }
    }

    bool EnemyCircle::checkCollision(Circle& other) const
    {
        return m_shape.getGlobalBounds().intersects(other.GetCircle().getGlobalBounds());
    }

    void EnemyCircle::update(float dt)
    {
        m_shape.setRadius(m_shape.getRadius() + m_growthRate * dt);
    }
}