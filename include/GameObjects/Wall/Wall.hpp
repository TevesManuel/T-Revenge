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

#include <iostream>
#include <Window/Window.hpp>
#include <Primitive/PrimitiveGraphics.hpp>

class Wall : public Object
{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        float sizeBox = 50;
    public:
        Wall(Window * windowPtr, WallTypes::types wallType);
        void render(sf::RenderWindow * windowPtr) override;
};
#endif
