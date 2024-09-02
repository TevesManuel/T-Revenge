#include <Window/Window.hpp>

Window::Window()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "T-Revenge", 0);
    this->window->setFramerateLimit(60);

    b2Vec2 gravity(0.0f, 0.0f);
    this->world = new b2World(gravity);
    this->world->SetContactListener(&this->contactListener);
}

void Window::addObject(Object * newObject)
{
    this->objects.push_back(newObject);
}

void Window::clearObjects()
{
    this->objects.clear();
}

void Window::clear(sf::Color bgcolor)
{
    this->window->clear(bgcolor);
}

void Window::display()
{
    this->window->display();
}

void Window::run()
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
        
        this->clear(sf::Color::Black);

        Object * object = NULL;
        for(int i = 0; i < objects.size(); i++)
        {
            object = objects.at(i);
            if(object->enabled)
            {
                object->update(this->window);
                object->render(this->window);
            }
        }

        this->display();
    }
}

b2Body * Window::addBodyDef(b2BodyDef * bodyDefPtr)
{
    return this->world->CreateBody(bodyDefPtr);
}

Window::~Window()
{
    delete world;
    delete window;
}