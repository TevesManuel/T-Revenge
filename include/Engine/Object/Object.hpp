#ifndef TEVES_OBJECT_HPP
#define TEVES_OBJECT_HPP

#include <string>
#include <Engine/Config.hpp>

class Object
{
    public:
        std::string label;
        bool enabled;
        bool toDestroy;
        unsigned int ID;
        Object ();
        virtual ~Object();
        virtual void onCollisionEnter(Object * collisionedObject);
        virtual void onCollisionExit(Object * collisionedObject);
        virtual void update(EngineWindow * windowPtr);
        virtual void render(EngineWindow * windowPtr);
        void destroy();
        void notificateCollisionEnter(Object * collisionedObject);
        void notificateCollisionExit(Object * collisionedObject);
};
#endif