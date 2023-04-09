/*
 * Vector.cpp
 * Created on: Apr 9, 2023
 *
 * Author: romaincaron
 */

#include "Vector.h"
#include <cmath>

/*
 * operator+
 * -----------------
 * Return the sum of two vectors
 * -----------------
 * @param other: the other vector
 */
void Vector::operator+=(const Vector &other) {
    x += other.x;
    y += other.y;
}

/*
 * operator-
 * -----------------
 * Return the difference of two vectors
 * -----------------
 * @param other: the other vector
 */
void Vector::operator-=(const Vector &other) {
    x -= other.x;
    y -= other.y;
}

/*
 * operator*
 * -----------------
 * Return the product of a vector and a coefficient
 * -----------------
 * @param coefficient: the coefficient
 */
Vector Vector::operator*(float coefficient) {
    return {x*coefficient, y*coefficient};
}

/*
 * createFromAngle
 * -----------------
 * Create a vector from an angle and a size
 * -----------------
 * @param size: the size of the vector
 * @param angleDegree: the angle of the vector
 * -----------------
 * @return the vector
 */
Vector Vector::createFromAngle(float size, float angleDegree) {
    return { static_cast<float>(size*cos(angleDegree/180 * M_PI)), static_cast<float>(size*sin(angleDegree/180 * M_PI)) };
}