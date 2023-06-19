#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"

using namespace sf;
using namespace game;

int main()
{
    // ������� ����
    RenderWindow window(VideoMode(800, 600), "My Game");
    Clock clock;
    // ������� �����
    PlayerCircle& player = PlayerCircle::getInstance();

    std::unique_ptr<EnemyCircle> enemy = std::make_unique<EnemyCircle>();
    // ������������� ��������� ������� ������
    player.setPosition(300.f, 300.f);
    // ������������� ��������� ������� �����
    enemy->setPosition(100.f, 100.f);

    // �������� ���� ����
    while (window.isOpen())
    {
        static float deltaTime = clock.getElapsedTime().asSeconds();

        // ������������ ������� � ����
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // Update ������
        player.update();

        // Update �����
        enemy->update(deltaTime, window);

        // ������������ ����� � ����
        window.clear();
        window.draw(player);
        window.draw(*enemy);
        window.display();
    }

    return 0;
}
