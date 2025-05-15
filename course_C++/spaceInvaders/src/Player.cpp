#include "Player.h"
#include <iostream>

sf::Texture Player::texture;

Player::Player(int startX, int startY) {
    if (texture.getSize().x == 0) {
        if (!texture.loadFromFile("assests/ship.png")) {
            std::cerr << "Error\n";
        }
        // else {
        //     std::cout << ")\n";
        // }
    }
    sprite.setTexture(texture);
    sprite.setPosition(static_cast<float>(startX), static_cast<float>(startY));
    sprite.setScale(0.1f, 0.1f);
}

void Player::moveLeft() {
    if (sprite.getPosition().x > 0) sprite.move(-5.f, 0.f);
}

void Player::moveRight(int maxX) {
    if (sprite.getPosition().x + sprite.getGlobalBounds().width < maxX) sprite.move(5.f, 0.f);
}

void Player::update() {}

int Player::getX() const {
    return sprite.getPosition().x;
}

int Player::getY() const {
    return sprite.getPosition().y;
}

Bullet* Player::shoot() {
    return new Bullet(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y, false);
}

const sf::Sprite& Player::getSprite() const {
    return sprite;
}