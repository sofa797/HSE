#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Explosion.h"
#include <vector>
#include <iostream>

std::vector<Explosion> explosions;

class Game {
public:
    Game();
    void run();
    void processInput();
    void update();
    void render();
    void spawnEnemies();
    void checkCollisions();
    int enemyShootTimer;
    const int enemyShootInterval = 500;
    int playerShootTimer;
    const int playerShootInterval = 20;
    int score;
    int level;
    int lives;
    sf::Font font;
    int fadeCounter = 0;
    bool fadingOut = false;

private:
    Player* player;
    std::vector<Bullet*> bullets;
    std::vector<Enemy> enemies;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    bool isRunning;
    sf::RenderWindow window;
    void deleteInactiveBullets();
    void updateEnemyMovement();
    void updateEnemyShooting();
    enum class GameState {
        startmenu,
        playing,
        gameover,
        victory
    };
    GameState gamestate;
};

#endif