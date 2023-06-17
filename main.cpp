#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Circle.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

using namespace sf;

int main()
{
    // Создаем окно
    RenderWindow window(VideoMode(800, 600), "My Game");

    // Создаем круги
    std::unique_ptr<PlayerCircle> player = std::make_unique<PlayerCircle>();
    std::unique_ptr<EnemyCircle> enemy = std::make_unique<EnemyCircle>();
    Clock clock;
    // Устанавливаем начальную позицию игрока
    player->setPosition(400.f, 300.f);

    // Устанавливаем начальную позицию врага
    enemy->setPosition(100.f, 100.f);

    // Основной цикл игры
    while (window.isOpen())
    {
        // Обрабатываем события в окне
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // Управление игроком
        player->handleInput();

        // Движение врага в сторону игрока
        enemy->followPlayer(*player);
        enemy->update(clock.restart().asSeconds());

        // Проверяем столкновение игрока и врага
        if (enemy->checkCollision(*player))
        {
            std::cout << "Game Over!" << std::endl;
            window.close();
        }

        // Отрисовываем круги в окне
        window.clear();
        window.draw(*player);
        window.draw(*enemy);
        window.display();
    }

    return 0;
}
