#pragma once
#include <SFML/Graphics.hpp>

namespace game
{
    class Timer
    {
    private:
        sf::Clock clock;
        sf::Font m_font;
        int m_timer;
    public:
        bool TimerIsOver();
        sf::Text m_seconds;
        Timer(int time);
        void update();
    };
}