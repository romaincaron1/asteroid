/*
 * Explosion.h
 * Created on: Apr 9, 2023
 *
 * Author: romaincaron
 */

#ifndef ASTEROID_EXPLOSION_H
#define ASTEROID_EXPLOSION_H

#include "../SpaceElement/SpaceElement.h"

class Explosion : public SpaceElement  {
public:
    explicit Explosion();
    void start(Coordinates const& p_position);
    void reactCollision() override;
    void display(sf::RenderWindow &window) const override;

protected:
    void update(float time) override;

private :
    bool started {false};
    float age{};
    static constexpr float LIFETIME {0.1f};
};


#endif //ASTEROID_EXPLOSION_H
