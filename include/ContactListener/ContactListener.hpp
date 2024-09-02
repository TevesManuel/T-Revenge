#ifndef TEVES_CONTACT_LISTNER_HPP
#define TEVES_CONTACT_LISTNER_HPP

#include <box2d/box2d.h>
#include <Object/Object.hpp>
#include <stdio.h>

class ContactListener : public b2ContactListener {
    public:
        void BeginContact(b2Contact* contact) override {
            b2Fixture* fixtureA = contact->GetFixtureA();
            b2Fixture* fixtureB = contact->GetFixtureB();

            Object * objectA = reinterpret_cast<Object*>(fixtureA->GetUserData().pointer);
            Object * objectB = reinterpret_cast<Object*>(fixtureB->GetUserData().pointer);

            printf("Notificando a el objeto(%d) y el objeto(%d) de inicio de colision\n", objectA->ID, objectB->ID);
            objectA->notificateCollisionEnter(objectB);
            objectB->notificateCollisionEnter(objectA);
        }

        void EndContact(b2Contact* contact) override {
            b2Fixture* fixtureA = contact->GetFixtureA();
            b2Fixture* fixtureB = contact->GetFixtureB();

            Object * objectA = reinterpret_cast<Object*>(fixtureA->GetUserData().pointer);
            Object * objectB = reinterpret_cast<Object*>(fixtureB->GetUserData().pointer);

            printf("Notificando a el objeto(%d) y el objeto(%d) de fin de colision\n", objectA->ID, objectB->ID);
            objectA->notificateCollisionExit(objectB);
            objectB->notificateCollisionExit(objectA);
        }
};

#endif