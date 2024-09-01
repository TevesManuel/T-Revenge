#ifndef TEVES_OBJECT_HPP
#define TEVES_OBJECT_HPP

#include <SFML/Graphics.hpp>

class Object
{
    public:
        bool enabled;
        unsigned int ID;
        Object ();
        virtual ~Object();
        virtual void update(sf::RenderWindow * windowPtr);
        virtual void render(sf::RenderWindow * windowPtr);
};
#endif