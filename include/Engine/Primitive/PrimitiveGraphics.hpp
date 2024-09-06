#ifndef TEVES_TPG_HPP
#define TEVES_TPG_HPP

#include <Engine/RenderWindow/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

namespace TPG // Teves Primitive Graphics
{
    void drawPoint(sf::Vector2f position, float size, RenderWindow * windowPtr, sf::Color color);
    void drawLine(sf::Vector2f p0, sf::Vector2f p1, RenderWindow * windowPtr, sf::Color color);
    void drawRect(sf::Vector2f position, sf::Vector2f size, RenderWindow * windowPtr, sf::Color color);
}

#endif