#include <Object/Object.hpp>

int lastObjectID = 0;

Object::Object ()
{
    this->enabled = true;
    this->ID = lastObjectID;
    lastObjectID++;
}
Object::~Object() {}
void Object::onCollisionEnter(Object * collisionedObject) {}
void Object::onCollisionExit(Object * collisionedObject) {}
void Object::update(sf::RenderWindow * windowPtr) {}
void Object::render(sf::RenderWindow * windowPtr) {}
void Object::notificateCollisionEnter(Object * collisionedObject)
{
    this->onCollisionEnter(collisionedObject);
}
void Object::notificateCollisionExit(Object * collisionedObject)
{
    this->onCollisionExit(collisionedObject);
}