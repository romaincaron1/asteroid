/*
 * Coordinates.h
 * Created on: Apr 9, 2023
 *
 * Author: romaincaron
 */

#ifndef ASTEROID_COORDINATES_H
#define ASTEROID_COORDINATES_H

#include "../Vector/Vector.h"

class Coordinates {
private :
    float x;
    float y;
    static float xMax;
    static float yMax;

public :
    Coordinates(float x, float y);
    float getX();
    float getY();
    static float getWidth();
    static float getHeight();
    static void initSpace(float width, float height);
    void operator+=(Vector const& vector);
    float calculateDistance(Coordinates const& other) const;
};


#endif //ASTEROID_COORDINATES_H
