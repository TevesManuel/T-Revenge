#include <Object/Object.hpp>

int lastObjectID = 0;

Object::Object ()
{
    this->enabled = true;
    this->ID = lastObjectID;
    lastObjectID++;
}
Object::~Object() {}
void Object::update(sf::RenderWindow * windowPtr) {}
void Object::render(sf::RenderWindow * windowPtr) {}