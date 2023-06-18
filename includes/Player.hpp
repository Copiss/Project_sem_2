#pragma once
#include"Circle.hpp"

namespace game
{
    // �������� ����� PlayerCircle
    class PlayerCircle : public Circle
    {
    public:
        static PlayerCircle& getInstance();

        void move(float x, float y);

        void handleInput();

    private:
        PlayerCircle(); // ����������� ������ ���� private
        PlayerCircle(const PlayerCircle&) = delete;
        PlayerCircle& operator=(const PlayerCircle&) = delete;
        static std::unique_ptr<PlayerCircle> instance;
    };
}