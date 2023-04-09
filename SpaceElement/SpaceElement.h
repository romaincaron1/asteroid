/*
 * SpaceElement.h
 * Created on: Apr 9, 2023
 *
 * Author: romaincaron
 */

#ifndef ASTEROID_SPACEELEMENT_H
#define ASTEROID_SPACEELEMENT_H


#include <SFML/Graphics.hpp>
#include "../Coordinates/Coordinates.h"
#include "../Vector/Vector.h"

class SpaceElement {
public:
    explicit SpaceElement(std::string_view const& pathImage);
    SpaceElement();
    void refresh(float time);
    virtual void display(sf::RenderWindow &window) const;
    float getRadius() const;
    void testCollision(SpaceElement &other);
    virtual void reactCollision() = 0;

protected:
    virtual void update(float time);
    sf::Texture texture;
    sf::Sprite sprite;
    Coordinates position { 400.f, 800.f};
    Vector velocity {0.f, 0.f};
    float angularVelocity {};
};


#endif //ASTEROID_SPACEELEMENT_H
