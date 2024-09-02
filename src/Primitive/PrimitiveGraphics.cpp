#include <Primitive/PrimitiveGraphics.hpp>

namespace TPG
{
    void drawLine(sf::Vector2f p0, sf::Vector2f p1, sf::RenderWindow * windowPtr, sf::Color color)
    {
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = p0;
        line[0].color = color;
        line[1].position = p1;
        line[1].color = color;
        windowPtr->draw(line);
    }
    void drawRect(sf::Vector2f position, sf::Vector2f size, sf::RenderWindow * windowPtr, sf::Color color)
    {
        drawLine(position, sf::Vector2f(position.x + size.x, position.y), windowPtr, color);    
        drawLine(sf::Vector2f(position.x + size.x, position.y), sf::Vector2f(position.x + size.x, position.y + size.y), windowPtr, color);    
        drawLine(sf::Vector2f(position.x + size.x, position.y + size.y), sf::Vector2f(position.x, position.y + size.y), windowPtr, color);
        drawLine(sf::Vector2f(position.x, position.y + size.y), sf::Vector2f(position.x, position.y), windowPtr, color);
    }
}