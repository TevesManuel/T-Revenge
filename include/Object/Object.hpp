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
        virtual void onCollisionEnter(Object * collisionedObject);
        virtual void onCollisionExit(Object * collisionedObject);
        virtual void update(sf::RenderWindow * windowPtr);
        virtual void render(sf::RenderWindow * windowPtr);
        void notificateCollisionEnter(Object * collisionedObject);
        void notificateCollisionExit(Object * collisionedObject);
};
#endif