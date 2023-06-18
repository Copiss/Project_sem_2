#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"

using namespace sf;
using namespace game;

int main()
{
    // ������� ����
    RenderWindow window(VideoMode(800, 600), "My Game");

    // ������� �����
    std::unique_ptr<PlayerCircle> player = std::make_unique<PlayerCircle>();
    std::unique_ptr<EnemyCircle> enemy = std::make_unique<EnemyCircle>();
    Clock clock;
    // ������������� ��������� ������� ������
    player->setPosition(400.f, 300.f);
    // ������������� ��������� ������� �����
    enemy->setPosition(100.f, 100.f);

    // �������� ���� ����
    while (window.isOpen())
    {
        // ������������ ������� � ����
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // ���������� �������
        player->handleInput();

        // �������� ����� � ������� ������
        enemy->followPlayer(*player);
        enemy->update(clock.restart().asSeconds());

        // ��������� ������������ ������ � �����
        if (enemy->checkCollision(*player))
        {
            std::cout << "Game Over!" << std::endl;
            window.close();
        }

        // ������������ ����� � ����
        window.clear();
        window.draw(*player);
        window.draw(*enemy);
        window.display();
    }

    return 0;
}
