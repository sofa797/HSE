#include "Enemy.h"
sf::Texture Enemy::texture;

Enemy::Enemy(int startX, int startY) : x(startX), y(startY), alive(true), movingRight(true), shootCooldown(0) {
    if (texture.getSize().x == 0) {
        if (!texture.loadFromFile("assests/ennem.png")) {
            std::cerr << "Ошибка загрузки enemy.png\n";
        }
        // else {
        //     std::cout << "Текстура врага успешно загружена\n";
        // }
    }
    
    sprite.setTexture(texture);
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    sprite.setScale(0.08f, 0.08f);
}

void Enemy::move() {
    if (movingRight) {
        sprite.move(1.f, 0.f);
        if (sprite.getPosition().x >= 800.f) {
            movingRight = false;
            sprite.move(0.f, 20.f);
        }
    } else {
        sprite.move(-1.f, 0.f);
        if (sprite.getPosition().x <= 0.f) {
            movingRight = true;
            sprite.move(0.f, 20.f);
        }
    }
}

bool Enemy::isAlive() const { return alive; }

int Enemy::getX() const { return static_cast<int>(sprite.getPosition().x); }

int Enemy::getY() const { return static_cast<int>(sprite.getPosition().y); }

void Enemy::die() { alive = false; }

void Enemy::changeDirection() {
    movingRight = !movingRight;
}

Bullet* Enemy::shoot() {
    if (canShoot()) {
        resetShootCooldown();
        return new Bullet(
            sprite.getPosition().x + sprite.getGlobalBounds().width / 2,
            sprite.getPosition().y + sprite.getGlobalBounds().height,
            true
        );
    }
    return nullptr;
}

void Enemy::updateshootCooldown() {
    if (shootCooldown > 0) {
        shootCooldown--;
    }
}

bool Enemy::canShoot() const {
    return shootCooldown <= 0;
}

void Enemy::moveHorizontally(int dx) {
    if (alive) sprite.move(static_cast<float>(dx), 0.f);
}

void Enemy::moveDown() {
    if (alive) sprite.move(0.f, 20.f);
}

// const sf::Rectanglesprite& Enemy::getShape() const {
//     return shape;
// }

void Enemy::resetShootCooldown() {
    shootCooldown = 100;
}

void Enemy::fadeOut() {
    if (color.a > 5) {
        color.a -= 5;
        sprite.setColor(color);
    } else {
        alive = false;
    }
}

const sf::Sprite& Enemy::getSprite() const {
    return sprite;
}