/*
 * Coordinates.cpp
 * Created on: Apr 9, 2023
 *
 * Author: romaincaron
 */

#include "Coordinates.h"
#include <cmath>
#include <algorithm>

using namespace std;

Coordinates::Coordinates(float _x, float _y) {
    x = _x;
    y = _y;
}

float Coordinates::getX() {
    return x;
}

float Coordinates::getY() {
    return y;
}

float Coordinates::getWidth() {
    return xMax;
}

float Coordinates::getHeight() {
    return yMax;
}

/*
 * initSpace
 * -----------------
 * Initializes the space.
 * -----------------
 * @param width : the width of the space
 * @param height : the height of the space
 * @return : the distance between the two coordinates
 */
void Coordinates::initSpace(float width, float height) {
    xMax = width;
    yMax = height;
}

/*
 * operator+=
 * -----------------
 * Adds a vector to the coordinates.
 * -----------------
 * @param vector : the vector to add
 */
void Coordinates::operator+=(const Vector &vector) {
    x += vector.x;
    y += vector.y;
    if (x > xMax) {
        x = 0;
    } else if (x < 0) {
        x = xMax;
    }
    if (y > yMax) {
        y = 0;
    } else if (y < 0) {
        y = yMax;
    }
}

/*
 * calculateDistance
 * -----------------
 * Calculates the distance between two coordinates.
 * -----------------
 * @param other : the other coordinates
 * @return : the distance between the two coordinates
 */
float Coordinates::calculateDistance(const Coordinates &other) const {
    auto delta = Vector{ min({ abs(x-other.x), abs(x-other.x-xMax), abs(x+other.x+xMax)}), min({ abs(y-other.y), abs(y-other.y-yMax), abs(y+other.y+yMax) }) };
    return sqrt(delta.x * delta.x + delta.y * delta.y);
}