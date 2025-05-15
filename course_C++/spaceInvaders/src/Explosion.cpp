#include "Explosion.h"
#include <iostream>

Explosion::Explosion(float x, float y) : lifetime(30) {
    if (!texture.loadFromFile("assests/explosion.png")) {
        std::cerr << "Failed to load explosion texture\n";
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width / 3, sprite.getGlobalBounds().height / 3);
    sprite.setPosition(x, y);
    sprite.setScale(0.08f, 0.08f);
}

void Explosion::update() {
    if (lifetime > 0) {
        --lifetime;
    }
}

bool Explosion::isFinished() const {
    return lifetime <= 0;
}

void Explosion::render(sf::RenderWindow& window) {
    if (!isFinished()) {
        window.draw(sprite);
    }
}