#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My Name");

    window.clear();

    sf::RectangleShape p1;
    p1.setSize({200, 50});
    p1.setPosition({50, 100});
    p1.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(p1);

    sf::RectangleShape p2;
    p2.setSize({50, 200});
    p2.setPosition({50, 100});
    p2.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(p2);

    sf::RectangleShape p3;
    p3.setSize({150, 50});
    p3.setPosition({50, 300});
    p3.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(p3);

    sf::RectangleShape p4;
    p4.setSize({50, 200});
    p4.setPosition({200, 300});
    p4.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(p4);

    sf::RectangleShape p5;
    p5.setSize({200, 50});
    p5.setPosition({50, 500});
    p5.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(p5);

    sf::RectangleShape f1;
    f1.setSize({50, 450});
    f1.setRotation(-9);
    f1.setPosition({300, 100});
    f1.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(f1);

    sf::RectangleShape f2;
    f2.setSize({50, 450});
    f2.setRotation(10);
    f2.setPosition({450, 100});
    f2.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(f2);

    sf::RectangleShape o1;
    o1.setSize({50, 450});
    o1.setPosition({550, 100});
    o1.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(o1);

    sf::RectangleShape o2;
    o2.setSize({200, 50});
    o2.setPosition({550, 100});
    o2.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(o2);

    sf::RectangleShape o3;
    o3.setSize({200, 50});
    o3.setPosition({550, 300});
    o3.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(o3);

    sf::RectangleShape o4;
    o4.setSize({200, 50});
    o4.setPosition({550, 500});
    o4.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(o4);

    window.display();

    sf::sleep(sf::seconds(5));
}