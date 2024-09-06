#ifndef TEVES_VECTOR2_HPP
#define TEVES_VECTOR2_HPP

#include <SFML/Graphics.hpp>

class Vector2
{
    public:
        float x, y;

        Vector2() : x(0), y(0) {}
        Vector2(float x, float y) : x(x), y(y) {}

        //sf::Vector2f compat

        // Constructor sf::Vector2f to Vector2
        Vector2(const sf::Vector2f& vec) : x(vec.x), y(vec.y) {}

        // Assignment operator from sf::Vector2f
        Vector2& operator=(const sf::Vector2f& vec) {
            x = vec.x;
            y = vec.y;
            return *this;
        }

        // Conversion operator to sf::Vector2f
        operator sf::Vector2f() const {
            return sf::Vector2f(x, y);
        }

        //sf::Vector2i compat

        Vector2(const sf::Vector2i& vec) : x(vec.x), y(vec.y) {}

        Vector2& operator=(const sf::Vector2i& vec) {
            x = vec.x;
            y = vec.y;
            return *this;
        }

        operator sf::Vector2i() const {
            return sf::Vector2i(x, y);
        }

        // b2Vec2 compat
        
        // Vector2(const b2Vec2& vec) : x(vec.x), y(vec.y) {}

        // Vector2& operator=(const b2Vec2& vec) {
        //     x = vec.x;
        //     y = vec.y;
        //     return *this;
        // }

        // operator b2Vec2() const {
        //     return b2Vec2(x, y);
        // }

        // Operands

        Vector2 operator+(const Vector2& anotherVec) const {
            return Vector2(x + anotherVec.x, y + anotherVec.y);
        }
};

#endif