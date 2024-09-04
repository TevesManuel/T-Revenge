#include <ContactListener/ContactListener.hpp>


void ContactListener::BeginContact(b2Contact* contact)
{
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    Object * objectA = reinterpret_cast<Object*>(fixtureA->GetUserData().pointer);
    Object * objectB = reinterpret_cast<Object*>(fixtureB->GetUserData().pointer);

    //Notificate the objects
    objectA->notificateCollisionEnter(objectB);
    objectB->notificateCollisionEnter(objectA);
}

void ContactListener::EndContact(b2Contact* contact) 
{
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    Object * objectA = reinterpret_cast<Object*>(fixtureA->GetUserData().pointer);
    Object * objectB = reinterpret_cast<Object*>(fixtureB->GetUserData().pointer);

    objectA->notificateCollisionExit(objectB);
    objectB->notificateCollisionExit(objectA);
}