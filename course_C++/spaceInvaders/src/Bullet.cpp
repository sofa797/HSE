#include "Bullet.h"
#include <ncurses.h>
#include <algorithm>

Bullet::Bullet(int startX, int startY, bool fromEnemy)
    : x(startX), y(startY), active(true), fromEnemy(fromEnemy) {}

void Bullet::moveUp() {
    if (active && y > 0) y -= 2.f;
    if (y <= 0) deactivate();
}

void Bullet::moveDown() {
    y += 2.f;
    if (y > 600) deactivate();
}

bool Bullet::isActive() const { return active; }
int Bullet::getX() const { return x; }
int Bullet::getY() const { return y; }
void Bullet::deactivate() { active = false; }
bool Bullet::isFromEnemy() const {
    return fromEnemy;
}