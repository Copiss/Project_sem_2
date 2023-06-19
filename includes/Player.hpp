#pragma once
#include"Circle.hpp"

namespace game
{
    // ƒочерний класс PlayerCircle
    class PlayerCircle : public Circle
    {
    public:
        static PlayerCircle& getInstance();
        void update();
    private:
        void move(float x, float y);
        void handleInput();

        PlayerCircle(); // конструктор должен быть private
        PlayerCircle(const PlayerCircle&) = delete;
        PlayerCircle& operator=(const PlayerCircle&) = delete;
        static std::unique_ptr<PlayerCircle> instance;
    };
}