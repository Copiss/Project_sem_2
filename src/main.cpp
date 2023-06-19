#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"

using namespace sf;
using namespace game;

int main()
{
    // Создаем окно
    RenderWindow window(VideoMode(800, 600), "My Game");
    Clock clock;
    // Создаем круги
    PlayerCircle& player = PlayerCircle::getInstance();

    std::unique_ptr<EnemyCircle> enemy = std::make_unique<EnemyCircle>();
    // Устанавливаем начальную позицию игрока
    player.setPosition(300.f, 300.f);
    // Устанавливаем начальную позицию врага
    enemy->setPosition(100.f, 100.f);

    // Основной цикл игры
    while (window.isOpen())
    {
        static float deltaTime = clock.getElapsedTime().asSeconds();

        // Обрабатываем события в окне
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // Update игрока
        player.update();

        // Update врага
        enemy->update(deltaTime, window);

        // Отрисовываем круги в окне
        window.clear();
        window.draw(player);
        window.draw(*enemy);
        window.display();
    }

    return 0;
}
