#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.hpp"

using namespace sf;

namespace pl
{
    void PlayerCircle::move(float x, float y)
    {
        m_shape.move(x, y);
    }

    void PlayerCircle::handleInput()
    {
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            move(-0.1f, 0.f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            move(0.1f, 0.f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            move(0.f, -0.1f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            move(0.f, 0.1f);
        }
    }
}