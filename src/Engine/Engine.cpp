#include <Engine/Engine.hpp>

Engine::Engine()
{
    this->rendererWindow = new RenderWindow();
    rendererWindow->setUserAddr(this);

    b2Vec2 gravity(0.0f, 0.0f);
    this->world = new b2World(gravity);
    this->world->SetContactListener(&this->contactListener);
}

void Engine::addObject(Object * newObject)
{
    this->objects.push_back(newObject);
}

void Engine::clearObjects()
{
    this->objects.clear();
}

void Engine::run()
{
    while (this->rendererWindow->isOpen())
    {
        sf::Event event;

        this->rendererWindow->pollEvents();
        
        //this->prevFrame.getElapsedTime().asSeconds() is deltaTime 
        this->world->Step(this->prevFrame.getElapsedTime().asSeconds(), 6, 2);
        this->prevFrame.restart();
        
        this->rendererWindow->clear();

        Object * object = NULL;

        for(int i = 0; i < objects.size(); i++)
        {
            object = objects.at(i);
            
            //check destroy
            while(object->toDestroy)
            {
                object->~Object();
                objects.erase(objects.begin() + i);
                if(i < objects.size())
                {
                    object = objects.at(i);
                }
                else
                {
                    object = nullptr;
                    break;
                }
            }

            //check integrity
            if(object)
            {
                if(object->enabled)
                {
                    object->update(this->rendererWindow);
                    object->render(this->rendererWindow);
                }
            }
        }

        this->rendererWindow->display();
    }
}

b2Body * Engine::addBodyDef(b2BodyDef * bodyDefPtr)
{
    return this->world->CreateBody(bodyDefPtr);
}

Engine::~Engine()
{
    delete this->world;
    delete this->rendererWindow;
}