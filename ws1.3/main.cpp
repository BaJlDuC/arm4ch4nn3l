#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <windows.h>
#include <iostream>

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Sprite Cat",
        sf::Style::Default, settings);
    sf::Texture cat;
    cat.loadFromFile("cat.png");

    sf::Sprite kitty;
    kitty.setTexture(cat);
    kitty.setPosition(400, 300);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color(0xFF, 0xFF, 0xFF));
        window.draw(kitty);
        window.display();
    }
}