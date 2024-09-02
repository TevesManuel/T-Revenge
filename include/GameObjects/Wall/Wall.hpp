#ifndef TEVES_WALL_HPP
#define TEVES_WALL_HPP

#include <Object/Object.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>

namespace WallTypes
{
    enum types
    {
        NORMAL
    };
}

class Wall : public Object
{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
    public:
        Wall(WallTypes::types wallType)
        {
            bool isLoaded = false;
            if(wallType == WallTypes::NORMAL)
            {
                isLoaded = this->texture.loadFromFile("./Assets/Sprites/Wall.png");
            }
            if(!isLoaded)
            {
                printf("\n---------------------------------------------------------\n");
                printf("[!] Error to load texture for Wall in %ds", clock() / CLOCKS_PER_SEC);
                printf("\n---------------------------------------------------------\n\n");
                exit(-1);
            }
            this->texture.setRepeated(true);
            this->sprite.setTexture(texture);
            this->sprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
            this->sprite.setPosition(sf::Vector2f(100, 100));
        }
        void render(sf::RenderWindow * windowPtr) override
        {
            windowPtr->draw(this->sprite);
        }
};
#endif
