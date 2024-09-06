#ifndef TEVES_WALL_HPP
#define TEVES_WALL_HPP

#include <Engine/Engine.hpp>
#include <Engine/Primitive/PrimitiveGraphics.hpp>
#include <Engine/Object/Object.hpp>
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

class Wall : public Object
{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        float sizeBox = 50;
    public:
        Wall(Engine * windowPtr, WallTypes::types wallType);
        void render(RenderWindow * windowPtr) override;
};
#endif
