#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>
#include <vector>

#define PLAYER_VELOCITY 100.0f

class Object
{
    public:
        void render(sf::RenderWindow * windowPtr);
};

class Player : Object
{
    private:

    public:
        Player()
        {

        }
        void render(sf::RenderWindow * windowPtr)
        {
            sf::RectangleShape rectangle(sf::Vector2f(120, 50)); // Tamaño del rectángulo
            rectangle.setFillColor(sf::Color::Green); // Color de relleno
            rectangle.setPosition(100, 100); // Posición en la ventana
            windowPtr->draw(rectangle);
        }
};

class Window
{
    private:
        sf::Clock prevFrame;
        b2World * world;
        sf::RenderWindow * window;
        std::vector<Object> objects;
    public:
        Window()
        {
            this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Box2D + SFML");
            this->window->setFramerateLimit(60);

            b2Vec2 gravity(0.0f, 0.0f);
            this->world = new b2World(gravity);
            // b2BodyDef groundBodyDef;
            // groundBodyDef.position.Set(0.0f, 0.0f);
            // b2Body* groundBody = world.CreateBody(&groundBodyDef);

            // b2EdgeShape groundBox;
            // groundBox.m_vertex1.Set(0, 500);
            // groundBox.m_vertex2.Set(800, 500);
            // groundBody->CreateFixture(&groundBox, 0.0f);

            // b2BodyDef bodyDef;
            // bodyDef.type = b2_dynamicBody;
            // bodyDef.position.Set(100.0f, 100.0f);
            // b2Body* body = world.CreateBody(&bodyDef);

            // b2PolygonShape dynamicBox;
            // dynamicBox.SetAsBox(20.0f, 20.0f);

            // b2FixtureDef fixtureDef;
            // fixtureDef.shape = &dynamicBox;
            // fixtureDef.density = 1.0f;
            // fixtureDef.friction = 0.3f;
            // body->CreateFixture(&fixtureDef);






        }
        void clear(sf::Color bgcolor)
        {
            this->window->clear(bgcolor);
        }
        void display()
        {
            this->window->display();
        }
        void run()
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

                for(int i = 0; i < objects.size(); i++)
                {
                    objects.at(i).render(this->window);
                }

                this->display();
           }
        }
};



int main()
{
    Window window;
    Player player;
    window.run();
    return 0;
}
