/*
 * SpaceElement.cpp
 * Created on: Apr 9, 2023
 *
 * Author: romaincaron
 */

#include "SpaceElement.h"
#include <iostream>
#include <array>

using namespace std;

SpaceElement::SpaceElement(string_view const& pathImage) {
    if (!texture.loadFromFile(pathImage.data())) {
        cerr << "Error loading " << pathImage << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(position.getX(), position.getY());
}

void SpaceElement::update(float time) {}

/*
 * refresh
 * -------
 * Updates the position of the SpaceElement
 * -------
 * @param time: the time elapsed since the last refresh
 * @return void
 */
void SpaceElement::refresh(float time) {
    update(time);
    auto relocation = velocity * time;
    position += relocation;
    sprite.setPosition(position.getX(), position.getY());
    sprite.rotate(angularVelocity * time);
}

void SpaceElement::display(sf::RenderWindow &window) const {
    auto displays = array<Vector, 9>{
            Vector {0.f, 0.f},
            Vector {0.f, 1.f},
            Vector {0.f, -1.f},
            Vector {1.f, 0.f},
            Vector {-1.f, 0.f},
            Vector {1.f, 1.f},
            Vector {1.f, -1.f},
            Vector {-1.f, 1.f},
            Vector {-1.f, -1.f}
    };
    for (auto const& display : displays) {
        auto transformation = sf::Transform();
        transformation.translate(display.x * Coordinates::getWidth(), display.y * Coordinates::getHeight());
        window.draw(sprite, transformation);
    }
}

float SpaceElement::getRadius() const {
    return sprite.getGlobalBounds().width / 2;
}

void SpaceElement::testCollision(SpaceElement &other) {
    auto distance = position.calculateDistance(other.position);
    if (distance < getRadius() + other.getRadius()) {
        reactCollision();
    }
}