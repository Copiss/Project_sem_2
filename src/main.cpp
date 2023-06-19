#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"

int main()
{
    
    // ������� ����
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
    // ������� �����
    game::PlayerCircle& player = game::PlayerCircle::getInstance();
    std::unique_ptr<game::EnemyCircle> enemy = std::make_unique<game::EnemyCircle>();
    // ������������� ��������� ������� ������
    player.setPosition(400.f, 300.f);
    // ������������� ��������� ������� �����
    enemy->setPosition(100.f, 100.f);
    sf::Clock clock;
    // �������� ���� ����
    while (window.isOpen())
    {
        window.setFramerateLimit(60);

        const float deltaTime = clock.restart().asSeconds();
        // ������������ ������� � ����
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        enemy->update(deltaTime, window);
        player.update();

        // ������������ ����� � ����
        window.clear();
        window.draw(*enemy);
        window.draw(player);
        window.display();
    }

    return 0;
}
