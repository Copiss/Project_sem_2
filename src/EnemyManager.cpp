#include "EnemyManager.hpp"
#include <iostream>
namespace game
{
    EnemyManager::EnemyManager(size_t numEnemies)
    {
        for (int i = 0; i < numEnemies; ++i) {
            m_enemies.push_back(std::make_unique<EnemyCircle>());
        }
    }

    void EnemyManager::update(float dt, sf::RenderWindow& window)
    {
        for (auto& enemy : m_enemies) {
            enemy->update(dt, window);
        }
    }

    void EnemyManager::draw(sf::RenderWindow& window)
    {
        for (auto& enemy : m_enemies) {
            window.draw(enemy->GetCircle());
        }
    }

    void EnemyManager::EndGame(sf::RenderWindow& window)
    {
        for (auto& enemy : m_enemies) {
            enemy->EndCondition(window);
        }
    }

    void EnemyManager::SetRandomPositions(sf::RenderWindow& window)
    {
        for (auto& enemy : m_enemies) {
            EnemyCircle::SetRandomPosition(*enemy, window);
        }
    }
}