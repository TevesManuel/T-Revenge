#ifndef TEVES_RENDERWINDOW_HPP
#define TEVES_RENDERWINDOW_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <Engine/Vector2/Vector2.hpp>

class RenderWindow
{
    private:
        sf::RenderWindow * window;
        void * userAddr;
    public:
        RenderWindow()
        {
            this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "T-Revenge", 0);
            this->window->setFramerateLimit(60);
        }
        
        void clear()
        {
            this->window->clear(sf::Color::Black);
        }

        void display()
        {
            this->window->display();
        }

        void draw(const sf::Drawable& drawable)
        {
            this->window->draw(drawable, sf::RenderStates::Default);
        }

        void pollEvents()
        {
            sf::Event event;
            while (this->window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    this->window->close();
            }
        }

        void setUserAddr(void * userAddr)
        {
            this->userAddr = userAddr;
        }

        void * getUserAddr()
        {
            return this->userAddr;
        }

        Vector2 getMousePosition()
        {
            return sf::Mouse::getPosition(*this->window);
        }

        bool isOpen()
        {
            return this->window->isOpen();
        }
        ~RenderWindow()
        {
            delete this->window;
        }
};

#endif