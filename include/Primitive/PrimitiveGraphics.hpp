#ifndef TEVES_TPG_HPP
#define TEVES_TPG_HPP

#include <SFML/Graphics.hpp>

namespace TPG // Teves Primitive Graphics
{
    void drawLine(sf::Vector2f p0, sf::Vector2f p1, sf::RenderWindow * windowPtr, sf::Color color);
    void drawRect(sf::Vector2f position, sf::Vector2f size, sf::RenderWindow * windowPtr, sf::Color color);
}

#endif