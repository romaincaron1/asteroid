/*
 * Asteroid.cpp
 * Created on: Apr 9, 2023
 *
 * Author: romaincaron
 */

#include "Asteroid.h"
#include <random>

using namespace std;

Asteroid::Asteroid() : SpaceElement("../assets/asteroid.png") {
    auto generator = random_device{};
    auto positionDistribution = uniform_real_distribution<float>{ -150, 150 };
    auto velocityDistribution = uniform_real_distribution<float>{ 80, 120 };
    auto angleDistribution = uniform_real_distribution<float>{ 0, 360 };
    auto angularVelocityDistribution = uniform_real_distribution<float>{ 10, 30 };
    position = { positionDistribution(generator), positionDistribution(generator) };
    velocity = Vector::createFromAngle(velocityDistribution(generator), angleDistribution(generator));
    angularVelocity = angularVelocityDistribution(generator);
}

void Asteroid::reactCollision() {

}