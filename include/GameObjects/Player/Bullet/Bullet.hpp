#include <Engine/Object/Object.hpp>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <math.h>

#define TEVES_BULLET_VEL 10

class Bullet : public Object
{
    private:
        sf::RectangleShape shape;
        sf::Vector2f direction;
    public:
        Bullet(sf::Vector2f initialPosition, float angle)
        {
            this->direction = sf::Vector2f(
                TEVES_BULLET_VEL * cos(angle),
                TEVES_BULLET_VEL * sin(angle)
            );
            shape.setRotation(angle * 180/b2_pi);
            shape.setSize(sf::Vector2f(10, 1));
            shape.setPosition(initialPosition);
            shape.setFillColor(sf::Color::Yellow);
        }
        void update(EngineWindow * windowPtr) override
        {
            if(this->shape.getPosition().x > 800.0f)
            {
                this->destroy();
            }
            this->shape.setPosition(shape.getPosition() + direction);
        }
        void render(EngineWindow * windowPtr) override
        {
            windowPtr->draw(shape);
        }
};