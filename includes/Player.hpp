#pragma once
#include"Circle.hpp"

namespace game
{
    class PlayerCircle : public Circle
    {
    public:
        static PlayerCircle& getInstance();
        void update();
    private:
        void move(float x, float y);
        void handleInput();

        PlayerCircle();
        PlayerCircle(const PlayerCircle&) = delete;
        PlayerCircle& operator=(const PlayerCircle&) = delete;
        static std::unique_ptr<PlayerCircle> instance;
    };
}