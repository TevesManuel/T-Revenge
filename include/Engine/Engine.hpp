#ifndef TEVES_WINDOW_HPP
#define TEVES_WINDOW_HPP

#include <box2d/box2d.h>
#include <Engine/Object/Object.hpp>
#include <vector>
#include <Engine/ContactListener/ContactListener.hpp>
#include <Engine/RenderWindow/RenderWindow.hpp>
#include <Engine/Vector2/Vector2.hpp>

class Engine
{
    private:
        sf::Clock prevFrame;
        b2World * world;
        RenderWindow * rendererWindow;
        std::vector<Object*> objects;
        ContactListener contactListener;
    public:
        Engine();
        void addObject(Object * newObject);
        void clearObjects();
        Vector2 getMousePosition();
        void run();
        b2Body * addBodyDef(b2BodyDef * bodyDefPtr);
        ~Engine();
};

#endif