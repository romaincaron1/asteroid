/*
 * Explosion.cpp
 * Created on: Apr 9, 2023
 *
 * Author: romaincaron
 */

#include "Explosion.h"

Explosion::Explosion() : SpaceElement("../assets/explosion.png") {

}

void Explosion::start(const Coordinates &p_position) {
    position = p_position;
    started = true;
}

void Explosion::update(float time) {
    if (started) {
        age += time;
    }
    if (age < LIFETIME) {
        sprite.setScale(age/LIFETIME, age/LIFETIME);
    }
}

void Explosion::display(sf::RenderWindow &window) const {
    if (age < LIFETIME) {
        SpaceElement::display(window);
    }
}

void Explosion::reactCollision() {}