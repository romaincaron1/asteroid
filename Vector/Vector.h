/*
 * Vector.h
 * Created on: Apr 9, 2023
 *
 * Author: romaincaron
 */

#ifndef ASTEROID_VECTOR_H
#define ASTEROID_VECTOR_H

struct Vector {
    float x{0.f};
    float y{0.f};

    void operator+=(Vector const& other);

    void operator-=(Vector const& other);

    Vector operator*(float coefficient);

    static Vector createFromAngle(float size, float angleDegree);
};


#endif //ASTEROID_VECTOR_H
