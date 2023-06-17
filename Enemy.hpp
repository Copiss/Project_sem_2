#pragma once
#include"Circle.hpp"

namespace game
{
    // Дочерний класс EnemyCircle
    class EnemyCircle : public Circle
    {
    public:
        EnemyCircle();

        void move(float x, float y);

        void followPlayer(const Circle& player);

        bool checkCollision(Circle& other) const;

        void update(float dt);

    private:
        float m_growthRate = 5;
    };

}