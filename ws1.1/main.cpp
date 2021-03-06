#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

// Структура хранит фигуры, составляющие стрелку, а также
//  позицию и поворот стрелки.
// После изменения позиции или поворота надо вызвать
//  функцию updateArrowElements, чтобы стрелка оставалась
//  в согласованном состоянии.
struct Arrow
{
    sf::ConvexShape head;
    sf::RectangleShape stem;
    sf::RectangleShape more;
    sf::Vector2f position;
    float rotation = 0;
};

// Переводит полярные координаты в декартовы
sf::Vector2f toEuclidean(float radius, float angle)
{
    return {
        radius * std::cos(angle),
        radius * std::sin(angle)};
}

// Переводит радианы в градусы
float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

// Обновляет позиции и повороты частей стрелки согласно текущему
// состоянию стрелки
void updateArrowElements(Arrow &arrow)
{
    const sf::Vector2f headOffset = toEuclidean(40, arrow.rotation);
    arrow.head.setPosition(arrow.position + headOffset);
    arrow.head.setRotation(toDegrees(arrow.rotation));

    const sf::Vector2f stemOffset = toEuclidean(-10, arrow.rotation);
    arrow.stem.setPosition(arrow.position);
    arrow.stem.setRotation(toDegrees(arrow.rotation));

    const sf::Vector2f moreOffset = toEuclidean(-10, arrow.rotation);
    arrow.more.setPosition(arrow.position);
    arrow.more.setRotation(toDegrees(arrow.rotation));
}

// Инициализирует фигуру-стрелку
void initArrow(Arrow &arrow)
{
    arrow.position = {400, 300};

    arrow.head.setPointCount(3);
    arrow.head.setPoint(0, {50, 0});
    arrow.head.setPoint(1, {0, -50});
    arrow.head.setPoint(2, {0, 50});
    arrow.head.setFillColor(sf::Color(0xFF, 0xFF, 0));
    arrow.head.setOutlineThickness(3);
    arrow.head.setOutlineColor(sf::Color(0, 0, 0));

    arrow.stem.setSize({60, 50});
    arrow.stem.setOrigin({20, 25});
    arrow.stem.setFillColor(sf::Color(0xFF, 0xFF, 0x00));
    arrow.stem.setOutlineThickness(3);
    arrow.stem.setOutlineColor(sf::Color(0, 0, 0));

    arrow.more.setSize({70, 50});
    arrow.more.setOrigin({20, 25});
    arrow.more.setFillColor(sf::Color(0xFF, 0xFF, 0x00));

    updateArrowElements(arrow);
}

// тут был эуклидеан угол

// тут был дегреес угол

// тут воидапдейт был

// Обрабатывает событие MouseMove, обновляя позицию мыши
void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

// Опрашивает и обрабатывает доступные события в цикле.
void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
        ;
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

// тут был полл еввент и объявление евента

// Обновляет фигуру, указывающую на мышь
void update(const sf::Vector2f &mousePosition, Arrow &arrow)
{
    const sf::Vector2f delta = mousePosition - arrow.position;
    arrow.rotation = atan2(delta.y, delta.x);
    updateArrowElements(arrow);
}

// Рисует и выводит один кадр
void redrawFrame(sf::RenderWindow &window, Arrow &arrow)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(arrow.stem);
    window.draw(arrow.head);
    window.draw(arrow.more);
    window.display();
}

// Программа рисует в окне стрелку, которая поворачивается вслед за курсором мыши.
int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Arrow follows mouse", sf::Style::Default, settings);

    Arrow arrow;
    sf::Vector2f mousePosition;

    initArrow(arrow);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, arrow);
        redrawFrame(window, arrow);
    }
}
