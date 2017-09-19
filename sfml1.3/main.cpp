#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "House");

    window.clear();

    sf::RectangleShape fund;
    fund.setSize({400, 200});
    fund.setPosition({200, 350});
    fund.setFillColor(sf::Color(0x8B, 0x45, 0x13));
    window.draw(fund);

    sf::RectangleShape door;
    door.setSize({75, 125});
    door.setPosition({250, 425});
    door.setFillColor(sf::Color(0xD, 0xD, 0xD));
    window.draw(door);

    sf::ConvexShape roof;
    roof.setFillColor(sf::Color(0xB2, 0x22, 0x22));
    roof.setPosition({400, 250});
    roof.setPointCount(4);
    roof.setPoint(0, {-100, 0});
    roof.setPoint(1, {+100, 0});
    roof.setPoint(2, {+250, 100});
    roof.setPoint(3, {-250, 100});
    window.draw(roof);

    sf::RectangleShape truba;
    truba.setSize({35, 75});
    truba.setPosition({450, 225});
    truba.setFillColor(sf::Color(0x80, 0x80, 0x80));
    window.draw(truba);

    sf::CircleShape smoke1(20);
    smoke1.setPosition({460, 160});
    smoke1.setFillColor(sf::Color(0xD3, 0xD3, 0xD3));
    window.draw(smoke1);

    sf::RectangleShape truba2;
    truba2.setSize({65, 50});
    truba2.setPosition({435, 195});
    truba2.setFillColor(sf::Color(0x80, 0x80, 0x80));
    window.draw(truba2);

    sf::CircleShape smoke2(25);
    smoke2.setPosition({470, 120});
    smoke2.setFillColor(sf::Color(0xD3, 0xD3, 0xD3));
    window.draw(smoke2);

    sf::CircleShape smoke3(30);
    smoke3.setPosition({495, 80});
    smoke3.setFillColor(sf::Color(0xD3, 0xD3, 0xD3));
    window.draw(smoke3);

    sf::CircleShape smoke4(35);
    smoke4.setPosition({520, 40});
    smoke4.setFillColor(sf::Color(0xD3, 0xD3, 0xD3));
    window.draw(smoke4);

    window.display();

    sf::sleep(sf::seconds(5));
}