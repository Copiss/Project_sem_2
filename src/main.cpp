#include <iostream>
#include "Player.hpp"
#include "EnemyManager.hpp"

int main()
{
    
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
    // Создаем круги
    game::EnemyManager manager(10);
    game::PlayerCircle& player = game::PlayerCircle::getInstance();
    // Устанавливаем начальную позицию игрока
    player.setPosition(400.f, 300.f);
    // Устанавливаем начальную позицию врага
    manager.SetRandomPositions(window);
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
        manager.update(deltaTime, window);
        player.update();

        // Отрисовываем круги в окне
        window.clear();
        window.draw(player);
        manager.draw(window);
        window.display();
    }

    return 0;
}
