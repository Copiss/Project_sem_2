#pragma once
#include <SFML/Graphics.hpp>

namespace game
{
    class Circle : public sf::Drawable {
    public:
        Circle(float radius = 0.f, sf::Color color = sf::Color::White);

        void setPosition(float x, float y);

        sf::Vector2f getPosition() const;

        float getRadius() const;

        const sf::CircleShape& GetCircle();

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    protected:
        sf::CircleShape m_shape;
    };
}