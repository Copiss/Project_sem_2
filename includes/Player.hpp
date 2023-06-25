#pragma once
#include"Circle.hpp"

namespace game
{
    class PlayerCircle : public Circle
    {
    public:
        static PlayerCircle& getInstance();
        void update(sf::RenderWindow& window);
        void PlayerWin(sf::RenderWindow& window);
        bool TimerIsOver();
    private:
        void move(float x, float y);
        void handleInput();
        sf::Clock clock;
        PlayerCircle();
        PlayerCircle(const PlayerCircle&) = delete;
        PlayerCircle& operator=(const PlayerCircle&) = delete;
        static std::unique_ptr<PlayerCircle> instance; 
    };
}