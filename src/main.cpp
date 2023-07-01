#include <iostream>
#include "Player.hpp"
#include "EnemyManager.hpp"
#include "Timer.hpp"
#include <SFML/Audio.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 710), "My Game");

    // Создать объект музыки и загрузить музыкальный файл
    sf::Music music;
    try {
        if (!music.openFromFile("background_music.wav")) {
            throw std::runtime_error("Failed to load music file");
        }
        music.setVolume(30); // Установить громкость в 30%
        music.setLoop(true); // Установить циклическое воспроизведение
        music.play(); // Запустить музыку
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::unique_ptr<game::Timer> t1 = std::make_unique<game::Timer>(20);
    std::unique_ptr<game::EnemyManager> manager = std::make_unique<game::EnemyManager>(3);
    game::PlayerCircle& player = game::PlayerCircle::getInstance();

    player.setPosition(800.f, 300.f);
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
        if (player.GetGameStatus() == false)
        {
            t1->update();
            manager->update(deltaTime, window);
            player.update();
        }

        window.clear();

        window.draw(player);
        manager->draw(window);
        window.draw(t1->m_seconds);
       
        manager->EndGame(window);                 
        player.PlayerWin(window, *t1);

        window.display();
    }

    return 0;
}