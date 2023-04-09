#include <iostream>
#include <array>
#include "main.h"
#include "Spaceship/Spaceship.h"
#include "Asteroid/Asteroid.h"
#include <vector>

float Coordinates::xMax = WIDTH;
float Coordinates::yMax = HEIGHT;

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Asteroid");

    auto vaisseau = Spaceship{ sf::Color::White };
    auto chrono = sf::Clock{};
    Asteroid Asteroid1{};
    Asteroid Asteroid2{};
    Asteroid Asteroid3{};
    Asteroid Asteroid4{};
    Coordinates::initSpace(WIDTH, HEIGHT);
    auto elements = vector<SpaceElement*>{ };
    auto partieEnCours = false;

    while(window.isOpen()) {
        auto event = sf::Event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && !partieEnCours) {
                elements.push_back(&vaisseau);
                elements.push_back(&Asteroid1);
                elements.push_back(&Asteroid2);
                elements.push_back(&Asteroid3);
                elements.push_back(&Asteroid4);
                partieEnCours = true;
            }
            vaisseau.refreshState(event);
        }
        auto temps_boucle = chrono.restart().asSeconds();

        for (SpaceElement* element : elements) {
            element->refresh(temps_boucle);
        }

        for (auto* element : elements) {
            for (auto* element2 : elements) {
                if (element != element2) {
                    element->testCollision(*element2);
                }
            }
        }

        window.clear(sf::Color::Black);

        for (auto*  element : elements) {
            element->display(window);
        }

        window.display();
    }

    return 0;
}
