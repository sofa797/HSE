#ifndef BULLET_H
#define BULLET_H

class Bullet {
private:
    float x, y;
    bool active;
    bool fromEnemy;

public:
    Bullet(int startX, int startY, bool fromEnemy);

    void moveUp();
    void moveDown();
    bool isFromEnemy() const;
    bool isActive() const;
    int getX() const;
    int getY() const;
    void deactivate();
    void deleteInactiveBullets();
};

#endif