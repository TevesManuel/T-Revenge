#include <SFML/Graphics.hpp>
#include <Engine/Object/Object.hpp>
#include <GameObjects/Player/Bullet/Bullet.hpp>
#include <box2d/box2d.h>
#include <Engine/Engine.hpp>

#include <vector>
#include <iostream>

class Player : public Object
{
    private:
        b2Body* body;
        sf::Texture texture;
        sf::Sprite sprite;
    public:
        Player(Engine * enginePtr);
        void onCollisionEnter(Object * collisionedObject) override;
        void update(RenderWindow * windowPtr) override;
        void render(RenderWindow * windowPtr) override;
};