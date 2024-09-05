#ifndef TEVES_WINDOW_HPP
#define TEVES_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <box2d/box2d.h>
#include <Engine/Object/Object.hpp>
#include <vector>
#include <Engine/ContactListener/ContactListener.hpp>

class Engine
{
    private:
        sf::Clock prevFrame;
        b2World * world;
        sf::RenderWindow * window;
        std::vector<Object*> objects;
        ContactListener contactListener;
    public:
        Engine();
        void addObject(Object * newObject);
        void clearObjects();
        sf::Vector2i getMousePosition();
        void run();
        b2Body * addBodyDef(b2BodyDef * bodyDefPtr);
        ~Engine();
};

#endif