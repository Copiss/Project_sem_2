#pragma once
#include"Enemy.hpp"
namespace game 
{
    class EnemyManager
    {
    public:
        EnemyManager(int numEnemies);
        void update(float dt, sf::RenderWindow& window);
        void draw(sf::RenderWindow& window);
        void EndGame(sf::RenderWindow& window);
        void SetRandomPositions(sf::RenderWindow& window);

    private:
        std::vector<std::unique_ptr<EnemyCircle>> m_enemies;
    };
}
