#include <iostream>
#include "Player.hpp"
#include "EnemyManager.hpp"
#include "Timer.hpp"

int main()
{
    game::Timer t1(15);
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");

    std::unique_ptr<game::EnemyManager> manager = std::make_unique<game::EnemyManager>(3);
    game::PlayerCircle& player = game::PlayerCircle::getInstance();

    player.setPosition(400.f, 300.f);

    manager->SetRandomPositions(window);
    sf::Clock Clock;
    window.setFramerateLimit(60);

    while (window.isOpen())
    {

        const float deltaTime = Clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        manager->update(deltaTime, window);
        player.update();
        window.clear();
        window.draw(player);
        window.draw(t1.m_seconds);
        t1.update();
        manager->draw(window);
        window.display();
    }

    return 0;
}