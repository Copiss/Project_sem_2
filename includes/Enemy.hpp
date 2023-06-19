#pragma once
#include"Circle.hpp"
#include"Player.hpp"

namespace game
{
    // Дочерний класс EnemyCircle
    class EnemyCircle : public Circle
    {
    public:
        EnemyCircle();

        void move(float x, float y);

        void followPlayer();

        bool checkCollision();

        void EndGame(sf::RenderWindow& window);

        void update(float dt, sf::RenderWindow& window);

    private:
        static float m_growthRate;
        static PlayerCircle& target;
    };

}