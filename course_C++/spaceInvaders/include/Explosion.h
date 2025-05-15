#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SFML/Graphics.hpp>

class Explosion {
    private:
    sf::Sprite sprite;
    sf::Texture texture;
    int lifetime;
    public:
    Explosion(float x, float y);
    void update();
    bool isFinished() const;
    void render(sf::RenderWindow& window);
};

#endif