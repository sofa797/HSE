#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Player {
    static sf::Texture texture;
    sf::Sprite sprite;
public:
    Player(int startX, int startY);
    void moveLeft();
    void moveRight(int maxX);
    void update();
    int getX() const;
    int getY() const;
    Bullet* shoot();
    const sf::Sprite& getSprite() const;
};

#endif