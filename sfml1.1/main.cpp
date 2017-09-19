#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({240, 570}), "Svetofor");

    window.clear();

    sf::RectangleShape osnova;
    osnova.setSize({200, 530});
    osnova.setPosition({20, 15});
    osnova.setFillColor(sf::Color(0x80, 0x80, 0x80));
    window.draw(osnova);

    sf::CircleShape krug1(75);
    krug1.setPosition({45, 25});
    krug1.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(krug1);

    sf::CircleShape krug2(75);
    krug2.setPosition({45, 200});
    krug2.setFillColor({0xFF, 0xFF, 0x0});
    window.draw(krug2);

    sf::CircleShape krug3(75);
    krug3.setPosition({45, 375});
    krug3.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(krug3);

    window.display();

    sf::sleep(sf::seconds(5));
}