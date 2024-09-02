#include <SFML/Graphics.hpp>
#include <Object/Object.hpp>
#include <box2d/box2d.h>
#include <Window/Window.hpp>

#include <iostream>

class Player : public Object
{
    private:
        b2BodyDef bodyDef;
        b2Body* body;
        sf::Texture texture;
        sf::Sprite sprite;
    public:
        Player(Window * windowPtr);
        void onCollisionEnter(Object * collisionedObject) override;
        void onCollisionExit(Object * collisionedObject) override;
        void update(sf::RenderWindow * windowPtr) override;
        void render(sf::RenderWindow * windowPtr) override;
};