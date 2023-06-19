#include <iostream>
#include "Player.hpp"
#include "EnemyManager.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");

    game::EnemyManager manager(10);
    game::PlayerCircle& player = game::PlayerCircle::getInstance();

    player.setPosition(400.f, 300.f);

    manager.SetRandomPositions(window);
    sf::Clock clock;

    while (window.isOpen())
    {
        window.setFramerateLimit(60);

        const float deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        manager.update(deltaTime, window);
        player.update();

        window.clear();
        window.draw(player);
        manager.draw(window);
        window.display();
    }

    return 0;
}