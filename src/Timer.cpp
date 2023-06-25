#include "Timer.hpp"

namespace game
{
    Timer::Timer(int time) : m_timer(time + 1)
    {
        m_font.loadFromFile("font.ttf");
        m_seconds.setFont(m_font);
        m_seconds.setFillColor(sf::Color::White);
        m_seconds.setCharacterSize(30);
        m_seconds.setPosition(30.f, 30.f);
    }

    bool Timer::TimerIsOver()
    {
        if (m_timer <= 0.f)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void Timer::update()
    {
        if (clock.getElapsedTime().asSeconds() >= 1.f)
        {
            m_timer--;
            m_seconds.setString(std::to_string(m_timer));
            clock.restart();
        }
    }
}