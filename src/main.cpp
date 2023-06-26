#include <iostream>
#include "Player.hpp"
#include "EnemyManager.hpp"
#include "Timer.hpp"

int main()
{
    game::Timer t1(15);
    sf::RenderWindow window(sf::VideoMode(1080,720), "My Game");

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
        if (player.Getter() == false)
        {
            t1.update();
            manager->update(deltaTime, window);
            player.update(window);
        }

        window.clear();

        window.draw(player);
        manager->draw(window);
        window.draw(t1.m_seconds);
        manager->EndGame(window);
        player.PlayerWin(window, t1);
        window.display();
    }

    return 0;
}