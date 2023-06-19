#pragma once
#include"Player.hpp"

namespace game
{
    // Дочерний класс EnemyCircle
    class EnemyCircle : public Circle
    {
    public:
        EnemyCircle();

        void update(float dt, sf::RenderWindow& window);

    private:
        static float m_growthRate;
        static PlayerCircle& GetTarget();
        void move(float x, float y);
        void followPlayer();
        bool checkCollision() const;
        void EndGame(sf::RenderWindow& window);
    };

}