#ifndef TEVES_CONTACT_LISTNER_HPP
#define TEVES_CONTACT_LISTNER_HPP

#include <box2d/box2d.h>

class ContactListener : public b2ContactListener {
    public:
        void BeginContact(b2Contact* contact) override;
        void EndContact(b2Contact* contact) override;
};

#endif