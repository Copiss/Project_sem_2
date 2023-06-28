#pragma once
#include"Circle.hpp"
#include "Timer.hpp"

namespace game
{
    class PlayerCircle : public Circle
    {
    public:
        static PlayerCircle& getInstance();
        void update();
        void PlayerWin(sf::RenderWindow& window, Timer& t);
        static bool GetGameStatus();
        static void SetGameStatus(bool n);
    private:
        static bool endGame;
        void move(float x, float y);
        void handleInput();
        void WinResult(sf::RenderWindow& window);
        PlayerCircle();
        PlayerCircle(const PlayerCircle&) = delete;
        PlayerCircle& operator=(const PlayerCircle&) = delete;
        static std::unique_ptr<PlayerCircle> instance; 
    };
}