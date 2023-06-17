#pragma once

namespace en
{
    // Дочерний класс EnemyCircle
    class EnemyCircle : public Circle
    {
    public:
        EnemyCircle() : Circle(20.f, Color::Red) {}

        void move(float x, float y);

        void followPlayer(const Circle& player);

        bool checkCollision(Circle& other) const;

        void update(float dt);

    private:
        float m_growthRate = 5;
    };

}