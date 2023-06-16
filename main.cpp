#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;

// Базовый класс Circle
class Circle : public Drawable
{
public:

    Circle(float radius = 0.f, Color color = Color::White) : m_shape(radius)
    {
        m_shape.setFillColor(color);
    }

    void setPosition(float x, float y)
    {
        m_shape.setPosition(x, y);
    }

    Vector2f getPosition() const
    {
        return m_shape.getPosition();
    }

    float getRadius() const
    {
        return m_shape.getRadius();
    }

    CircleShape& GetCircle()
    {
        return m_shape;
    }

    void draw(RenderTarget& target, RenderStates states) const override // переопределение метода
    {
        target.draw(m_shape, states);
    }

protected:
    CircleShape m_shape;
};

// Дочерний класс PlayerCircle
class PlayerCircle : public Circle
{
public:
    PlayerCircle() : Circle(30.f, Color::Green) {}

    void move(float x, float y)
    {
        m_shape.move(x, y);
    }

    void handleInput()
    {
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            move(-0.1f, 0.f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            move(0.1f, 0.f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            move(0.f, -0.1f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            move(0.f, 0.1f);
        }
    }
};

// Дочерний класс EnemyCircle
class EnemyCircle : public Circle
{
public:
    EnemyCircle() : Circle(20.f, Color::Red) {}

    void move(float x, float y)
    {
        m_shape.move(x, y);
    }

    void followPlayer(const Circle& player)
    {
        if (player.getPosition().x > m_shape.getPosition().x)
        {
            move(0.01f, 0.f);
        }
        if (player.getPosition().x < m_shape.getPosition().x)
        {
            move(-0.01f, 0.f);
        }
        if (player.getPosition().y > m_shape.getPosition().y)
        {
            move(0.f, 0.01f);
        }
        if (player.getPosition().y < m_shape.getPosition().y)
        {
            move(0.f, -0.01f);
        }
    }

    bool checkCollision(Circle& other) const
    {
        return m_shape.getGlobalBounds().intersects(other.GetCircle().getGlobalBounds());
    }

    void update(float dt)
    {
        m_shape.setRadius(m_shape.getRadius() + m_growthRate * dt);
    }

private:
    float m_growthRate = 5;
};

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
