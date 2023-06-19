#pragma once
#include"Player.hpp"

namespace game
{
    class EnemyCircle : public Circle
    {
    public:
        EnemyCircle();
        static void SetRandomPosition(EnemyCircle& enemy, sf::RenderWindow& window);
        void update(float dt, sf::RenderWindow& window);
        bool checkCollision() const;
        void EndCondition(sf::RenderWindow& window);

    private:
        static float m_growthRate;
        static PlayerCircle& GetTarget();
        void move(float x, float y);
        void followPlayer();
    };
}