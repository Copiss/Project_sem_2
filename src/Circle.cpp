#include "Circle.hpp"

namespace game
{
    Circle::Circle(float radius, sf::Color color) {
        m_shape = std::make_unique<sf::CircleShape>(radius);
        m_shape->setFillColor(color);
    }

    Circle::~Circle(){
    }

    void Circle::setPosition(float x, float y) {
        m_shape->setPosition(x, y);
    }

    sf::Vector2f Circle::getPosition() const {
        return m_shape->getPosition();
    }

    float Circle::getRadius() const {
        return m_shape->getRadius();
    }

    const sf::CircleShape& Circle::GetCircle() {
        return *m_shape;
    }

    void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(*m_shape, states);
    }
}