#ifndef TEVES_WINDOW_HPP
#define TEVES_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <Object/Object.hpp>
#include <vector>
#include <ContactListener/ContactListener.hpp>

class Window
{
    private:
        sf::Clock prevFrame;
        b2World * world;
        sf::RenderWindow * window;
        std::vector<Object*> objects;
        ContactListener contactListener;
    public:
        Window();
        void addObject(Object * newObject);
        void clearObjects();
        void clear(sf::Color bgcolor);
        void display();
        void run();
        b2Body * addBodyDef(b2BodyDef * bodyDefPtr);
        ~Window();
};

#endif