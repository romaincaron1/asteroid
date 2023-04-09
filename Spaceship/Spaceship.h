/*
 * Spaceship.h
 * Created on: Apr 9, 2023
 *
 * Author: romaincaron
 */

#ifndef ASTEROID_SPACESHIP_H
#define ASTEROID_SPACESHIP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Vector/Vector.h"
#include "../Coordinates/Coordinates.h"
#include "../SpaceElement/SpaceElement.h"
#include "../Explosion/Explosion.h"

class Spaceship : public SpaceElement {
public:
    explicit Spaceship(sf::Color const& color);
    void refreshState(sf::Event const& event);
    void reactCollision() override;
    void display(sf::RenderWindow &window) const override;

protected:
    void update(float time) override;

private:
    bool isMoving = false;
    bool turnLeft = false;
    bool turnRight = false;
    bool destroyed = false;

    Explosion explosion;

    static constexpr float ACCELERATION{ 700.f };
    static constexpr float FRICTION_COEFFICIENT{ 1.f };
    static constexpr float ANGULAR_VELOCITY{ 180.f };

};


#endif //ASTEROID_SPACESHIP_H
