#include "EnemyManager.hpp"
#include <iostream>

namespace game
{
    EnemyManager::EnemyManager(size_t numEnemies)
    {
        try {
            if (numEnemies == 0) {
                throw std::invalid_argument("Number of enemies should be greater than zero");
            }
            for (int i = 0; i < numEnemies; ++i) {
                m_enemies.push_back(std::make_unique<EnemyCircle>());
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
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
            enemy->SetRandomPosition(*enemy, window);
        }
    }
}