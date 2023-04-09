/*
 * Asteroid.h
 * Created on: Apr 9, 2023
 *
 * Author: romaincaron
 */

#ifndef ASTEROID_ASTEROID_H
#define ASTEROID_ASTEROID_H

#include <SFML/Graphics.hpp>
#include "../SpaceElement/SpaceElement.h"

class Asteroid : public SpaceElement {
public:
    explicit Asteroid();
    void reactCollision() override;
};


#endif //ASTEROID_ASTEROID_H
