#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

struct Eye_R
{
    sf::ConvexShape ellipseR;
    sf::ConvexShape zra4okR;
    sf::Vector2f position;
    float rotation = 0;
};

struct Eye_L
{
    sf::ConvexShape ellipseL;
    sf::ConvexShape zra4okL;
    sf::Vector2f position;
    float rotation = 0;
};

sf::Vector2f toEuclidean(float radiusX, float radiusY, float angle)
{
    return {
        radiusX * std::cos(angle),
        radiusY * std::sin(angle)};
}

void updateEye_RElements(Eye_R &eye_R)
{
    eye_R.ellipseR.setPosition(eye_R.position);

    const sf::Vector2f headOffset = toEuclidean(20, 40, eye_R.rotation);
    eye_R.zra4okR.setPosition(eye_R.position + headOffset);
}

void initEye_R(Eye_R &eye_R)
{
    constexpr int pointCount = 200;
    eye_R.position = {340, 300};

    const sf::Vector2f ellipseRadius = {40.f, 80.f};
    eye_R.ellipseR.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    eye_R.ellipseR.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            ellipseRadius.x * std::sin(angle),
            ellipseRadius.y * std::cos(angle)};
        eye_R.ellipseR.setPoint(pointNo, point);
    }

    const sf::Vector2f zra4okRadius = {10.f, 20.f};
    eye_R.zra4okR.setFillColor(sf::Color(0x0, 0x0, 0x0));
    eye_R.zra4okR.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            zra4okRadius.x * std::sin(angle),
            zra4okRadius.y * std::cos(angle)};
        eye_R.zra4okR.setPoint(pointNo, point);
    }
    updateEye_RElements(eye_R);
}

void updateEye_LElements(Eye_L &eye_L)
{
    eye_L.ellipseL.setPosition(eye_L.position);

    const sf::Vector2f headOffset = toEuclidean(20, 40, eye_L.rotation);
    eye_L.zra4okL.setPosition(eye_L.position + headOffset);
}

void initEye_L(Eye_L &eye_L)
{
    constexpr int pointCount = 200;
    eye_L.position = {460, 300};

    const sf::Vector2f ellipseRadius = {40.f, 80.f};
    eye_L.ellipseL.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    eye_L.ellipseL.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            ellipseRadius.x * std::sin(angle),
            ellipseRadius.y * std::cos(angle)};
        eye_L.ellipseL.setPoint(pointNo, point);
    }

    const sf::Vector2f zra4okRadius = {10.f, 20.f};
    eye_L.zra4okL.setFillColor(sf::Color(0x0, 0x0, 0x0));
    eye_L.zra4okL.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            zra4okRadius.x * std::sin(angle),
            zra4okRadius.y * std::cos(angle)};
        eye_L.zra4okL.setPoint(pointNo, point);
    }
    updateEye_LElements(eye_L);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouseX =" << event.x << ", Y =" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
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

void update(const sf::Vector2f &mousePosition, Eye_R &eye_R, Eye_L &eye_L)
{
    const sf::Vector2f delta_R = mousePosition - eye_R.position;
    eye_R.rotation = atan2(delta_R.y, delta_R.x);
    updateEye_RElements(eye_R);

    const sf::Vector2f delta_L = mousePosition - eye_L.position;
    eye_L.rotation = atan2(delta_L.y, delta_L.x);
    updateEye_LElements(eye_L);
}

void redrawFrame(sf::RenderWindow &window, Eye_R &eye_R, Eye_L &eye_L)
{
    window.clear();
    window.draw(eye_R.ellipseR);
    window.draw(eye_R.zra4okR);
    window.draw(eye_L.ellipseL);
    window.draw(eye_L.zra4okL);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Amazing Eyes", sf::Style::Default, settings);

    Eye_R eye_R;
    Eye_L eye_L;

    sf::Vector2f mousePosition;

    initEye_R(eye_R);
    initEye_L(eye_L);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, eye_R, eye_L);
        redrawFrame(window, eye_R, eye_L);
    }
}
