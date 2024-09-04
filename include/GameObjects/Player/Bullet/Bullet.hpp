#include<Object/Object.hpp>
#include<SFML/Graphics.hpp>

class Bullet : public Object
{
    private:
        sf::RectangleShape shape;
    public:
        Bullet()
        {
            shape.setSize(sf::Vector2f(10, 1));
            shape.setPosition(sf::Vector2f(100, 100));
            shape.setFillColor(sf::Color::Yellow);
        }
        void update(sf::RenderWindow * windowPtr) override
        {
            shape.setPosition(shape.getPosition() + sf::Vector2f(1, 0));
        }
        void render(sf::RenderWindow * windowPtr) override
        {
            windowPtr->draw(shape);
        }
};