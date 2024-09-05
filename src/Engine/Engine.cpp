#include <Engine/Engine.hpp>

Engine::Engine()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "T-Revenge", 0);
    this->window->setFramerateLimit(60);

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
    while (this->window->isOpen())
    {
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window->close();
        }
        
        //this->prevFrame.getElapsedTime().asSeconds() is deltaTime 
        this->world->Step(this->prevFrame.getElapsedTime().asSeconds(), 6, 2);
        this->prevFrame.restart();
        
        this->window->clear(sf::Color::Black);

        Object * object = NULL;

        for(int i = 0; i < objects.size(); i++)
        {
            object = objects.at(i);
            
            //check destroy
            while(object->toDestroy)
            {
                printf("%d\n", objects.size());
                objects.erase(objects.begin() + i);
                printf("%d\n", objects.size());
                if(i < objects.size())
                {
                    object = objects.at(i);
                }
                else
                {
                    object = nullptr;
                }
            }

            //check integrity
            if(object)
            {
                if(object->enabled)
                {
                    object->update(this->window);
                    object->render(this->window);
                }
            }
        }

        this->window->display();
    }
}

b2Body * Engine::addBodyDef(b2BodyDef * bodyDefPtr)
{
    return this->world->CreateBody(bodyDefPtr);
}

sf::Vector2i Engine::getMousePosition()
{
    return sf::Mouse::getPosition(*this->window);
}

Engine::~Engine()
{
    delete world;
    delete window;
}