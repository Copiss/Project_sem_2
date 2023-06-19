#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"

int main()
{
    
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
    // Создаем круги
    game::PlayerCircle& player = game::PlayerCircle::getInstance();
    std::unique_ptr<game::EnemyCircle> enemy = std::make_unique<game::EnemyCircle>();
    // Устанавливаем начальную позицию игрока
    player.setPosition(400.f, 300.f);
    // Устанавливаем начальную позицию врага
    enemy->setPosition(100.f, 100.f);
    sf::Clock clock;
    // Основной цикл игры
    while (window.isOpen())
    {
        window.setFramerateLimit(60);

        const float deltaTime = clock.restart().asSeconds();
        // Обрабатываем события в окне
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        enemy->update(deltaTime, window);
        player.update();

        // Отрисовываем круги в окне
        window.clear();
        window.draw(*enemy);
        window.draw(player);
        window.display();
    }

    return 0;
}
