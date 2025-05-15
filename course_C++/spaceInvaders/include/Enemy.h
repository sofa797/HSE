#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <iostream>

class Enemy {
    int x, y;
    bool alive;
    bool movingRight;
    int shootCooldown;
    sf::RectangleShape shape;
    sf::Color color = sf::Color::White;
    static sf::Texture texture;
    sf::Sprite sprite;
public:
    Enemy(int startX, int startY);
    void move();
    bool isAlive() const;
    int getX() const;
    int getY() const;
    void die();
    void changeDirection();
    Bullet* shoot();
    void updateshootCooldown();
    bool canShoot() const;
    void moveHorizontally(int dx);
    void moveDown();
    void resetShootCooldown();
    void fadeOut();
    const sf::Sprite& getSprite() const;
};

#endif