#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Circle.hpp"

using namespace sf;

namespace cr
{
    Circle::Circle(float radius = 0.f, Color color = Color::White) : m_shape(radius)
    {
        m_shape.setFillColor(color);
    }

    void Circle::setPosition(float x, float y)
    {
        m_shape.setPosition(x, y);
    }

    Vector2f Circle::getPosition() const
    {
        return m_shape.getPosition();
    }

    float Circle::getRadius() const
    {
        return m_shape.getRadius();
    }

    CircleShape& Circle::GetCircle()
    {
        return m_shape;
    }

    void Circle::draw(RenderTarget& target, RenderStates states) const override // переопределение метода
    {
        target.draw(m_shape, states);
    }
}