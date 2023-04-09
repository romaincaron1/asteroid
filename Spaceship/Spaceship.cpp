/*
 * Spaceship.cpp
 * Created on: Apr 9, 2023
 *
 * Author: romaincaron
 */

#include "Spaceship.h"

using namespace std;

Spaceship::Spaceship(sf::Color const& color) : SpaceElement("../assets/ship.png") {
    sprite.setColor(color);
}

void Spaceship::refreshState(sf::Event const& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
        turnRight = true;
    } else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right) {
        turnRight = false;
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
        turnLeft = true;
    } else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left) {
        turnLeft = false;
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
        isMoving = true;
    } else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
        isMoving = false;
    }
}

void Spaceship::update(float time) {
    if (!destroyed) {
        if (isMoving) {
            velocity += Vector::createFromAngle(ACCELERATION * time, sprite.getRotation());
        }
        velocity -= velocity * FRICTION_COEFFICIENT * time;
        if (turnLeft) {
            angularVelocity = -ANGULAR_VELOCITY;
            sprite.rotate(-ANGULAR_VELOCITY * time);
        }
        if (turnRight) {
            angularVelocity = ANGULAR_VELOCITY;
            sprite.rotate(ANGULAR_VELOCITY * time);
        } else {
            angularVelocity = 0;
        }
    }

    explosion.refresh(time);
}

void Spaceship::reactCollision() {
    if (!destroyed) {
        destroyed = true;
        explosion.start(position);
    }
}

void Spaceship::display(sf::RenderWindow &window) const {
    if (!destroyed) {
        SpaceElement::display(window);
    } else {
        explosion.display(window);
    }
}