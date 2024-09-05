#include <Engine/Object/Object.hpp>

int lastObjectID = 0;

Object::Object ()
{
    this->enabled = true;
    this->toDestroy = false;
    this->ID = lastObjectID;
    lastObjectID++;
    printf("Object with ID %d has been created.\n", this->ID);
}
Object::~Object()
{
    printf("Object with ID %d has been destroyed.\n", this->ID);
}
void Object::onCollisionEnter(Object * collisionedObject) {}
void Object::onCollisionExit(Object * collisionedObject) {}
void Object::update(sf::RenderWindow * windowPtr) {}
void Object::render(sf::RenderWindow * windowPtr) {}
void Object::destroy()
{
    this->toDestroy = true;
}
void Object::notificateCollisionEnter(Object * collisionedObject)
{
    this->onCollisionEnter(collisionedObject);
}
void Object::notificateCollisionExit(Object * collisionedObject)
{
    this->onCollisionExit(collisionedObject);
}