#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int enemyMoveCounter = 0;
int enemyMoveDelay = 80;

Game::Game() : player(nullptr), isRunning(true), gamestate(GameState::startmenu) {
    window.create(sf::VideoMode(800, 600), "Space Invaders");
    if (!backgroundTexture.loadFromFile("assests/space.gif")) {
        std::cerr << "ошибка загрузки space.png" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    backgroundSprite.setScale(scaleX, scaleY);
    backgroundSprite.setColor(sf::Color(255, 255, 255, 150));
    spawnEnemies();
    player = new Player(400, 490);
    enemyShootTimer = 0;
    playerShootTimer = 0;
    score = 0;
    level = 1;
    lives = 3;
    font.loadFromFile("Matroska-RppG6.ttf");
}

void Game::run() {
    while (window.isOpen()) {
        processInput();
        render();
        if (gamestate == GameState::playing) {
            update();
        }
        if (fadingOut && fadeCounter > 200) {
            sf::sleep(sf::seconds(1));
            window.close();
        }
    }
}

void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            isRunning = false;
        }
        if (gamestate == GameState::startmenu) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                gamestate = GameState::playing;
                return;
            }
        }
    }
    if (gamestate != GameState::playing) {
        return;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player->moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player->moveRight(window.getSize().x);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (playerShootTimer >= playerShootInterval) {
            bullets.push_back(player->shoot());
            playerShootTimer = 0;
        }
    }    
}

void Game::update() {
    playerShootTimer++;

    for (auto& bullet : bullets) {
        if (bullet->isFromEnemy()) bullet->moveDown();
        else bullet->moveUp();
    }

    if (isRunning) {
        updateEnemyMovement();
        updateEnemyShooting();
        checkCollisions();

        bool allEnemiesDead = std::all_of(enemies.begin(), enemies.end(), [](const Enemy& e) {
            return !e.isAlive();
        });

        if (allEnemiesDead) {
            level++;
            enemyMoveDelay = std::max(20, enemyMoveDelay - 10);
            spawnEnemies();
        }
    } else if (lives <= 0) {
        fadingOut = true;
        for (auto& enemy : enemies) {
            enemy.fadeOut();
        }
        gamestate = GameState::gameover;

        fadeCounter++;
    }
    for (auto& expl : explosions) {
        expl.update();
    }
    explosions.erase(std::remove_if(explosions.begin(), explosions.end(), [](const Explosion& e) { return e.isFinished();}), explosions.end());

    deleteInactiveBullets();
}


void Game::render() {
    window.clear();

    window.draw(backgroundSprite);

    if (gamestate == GameState::startmenu) {
        sf::Text title("SPACE INVADERS", font, 40);
        title.setFillColor(sf::Color::White);
        title.setPosition(98, 150);
        window.draw(title);

        sf::Text prompt("---> START <---", font, 25);
        sf::Text expl("Tap Enter", font, 9);
        prompt.setFillColor(sf::Color::Green);
        expl.setFillColor(sf::Color::Green);
        prompt.setPosition(250, 300);
        expl.setPosition(350, 350);
        window.draw(prompt);
        window.draw(expl);

        window.display();
        return;
    }

    if (player) {
        window.draw(player->getSprite());
    }

    for (const auto& enemy : enemies) {
        if (enemy.isAlive()) {
            window.draw(enemy.getSprite());
        }
    }
    // std::cout << "Start rendering bullets" << std::endl;
    // std::cout << "Enemies count: " << enemies.size() << std::endl;
    // std::cout << "End rendering bullets" << std::endl;

    for (const auto& bullet : bullets) {
        // std::cout << "Bullet active: " << bullet->isActive() << std::endl;

        if (bullet->isActive()) {
            sf::RectangleShape bulletShape(sf::Vector2f(3, 10));
            bulletShape.setFillColor(bullet->isFromEnemy() ? sf::Color::Red : sf::Color::Green);
            bulletShape.setPosition(bullet->getX(), bullet->getY());
            window.draw(bulletShape);
        }
    }

    for (auto& expl : explosions) {
        expl.render(window);
    }

    sf::Text uiText;
    uiText.setFont(font);
    uiText.setCharacterSize(20);
    uiText.setFillColor(sf::Color::White);
    uiText.setString("Score: " + std::to_string(score) +
                    "   Level: " + std::to_string(level) +
                    "   Lives: " + std::to_string(lives));
    uiText.setPosition(10, 10);
    window.draw(uiText);

    if (!isRunning || lives <= 0) {
        enemies.clear();
        fadingOut = true;
        sf::Text gameOverText("Game Over", font, 50);
        gameOverText.setFillColor(sf::Color::Red);

        sf::FloatRect textBounds = gameOverText.getLocalBounds();

        gameOverText.setPosition(
            (window.getSize().x - textBounds.width) / 9,
            (window.getSize().y - textBounds.height) / 6
        );

        window.draw(gameOverText);
    }

    window.display();
}

void Game::spawnEnemies() {
    const int top = 50;
    for (int i = 0; i < 50; ++i) {
        int startX = (i % 10) * 50;
        int startY = (i / 10) * 50 + top;
        enemies.push_back(Enemy(startX, startY));
    }
}

void Game::updateEnemyMovement() {
    static bool movingRight = true;
    static int moveCounter = 0;

    if (++enemyMoveCounter >= enemyMoveDelay) {
        enemyMoveCounter = 0;

        float leftMost = 800, rightMost = 0;

        for (const auto& enemy : enemies) {
            if (!enemy.isAlive()) continue;
            float x = enemy.getX();
            if (x < leftMost) leftMost = x;
            if (x > rightMost) rightMost = x;
        }

        bool atEdge = (movingRight && rightMost + 30 >= 800) ||
                      (!movingRight && leftMost <= 0);

        if (atEdge) {
            movingRight = !movingRight;
            for (auto& enemy : enemies) {
                if (enemy.isAlive()) {
                    enemy.moveDown();
                    if (enemy.getY() + 30 >= player->getY()) {
                        isRunning = false;
                        fadingOut = true;
                        enemies.clear();
                        return;
                    }
                }
            }
        } else {
            int dx = movingRight ? 5 : -5;
            for (auto& enemy : enemies) {
                if (enemy.isAlive()) {
                    enemy.moveHorizontally(dx);
                }
            }
        }
    }
}

void Game::updateEnemyShooting() {
    for (auto& enemy : enemies) {
        enemy.updateshootCooldown();
    }

    if (++enemyShootTimer >= enemyShootInterval) {
        std::vector<Enemy*> aliveEnemies;
        for (auto& enemy : enemies) {
            if (enemy.isAlive() && enemy.canShoot()) {
                aliveEnemies.push_back(&enemy);
            }
        }

        if (!aliveEnemies.empty()) {
            int idx = rand() % aliveEnemies.size();
            Bullet* bullet = aliveEnemies[idx]->shoot();
            if (bullet != nullptr) {
                bullets.push_back(bullet);
            }
        }
        
        enemyShootTimer = 0;
    }
}

void Game::checkCollisions() {
    for (auto& bullet : bullets) {
        if (!bullet->isActive()) continue;

        if (!bullet->isFromEnemy()) {
            for (auto& enemy : enemies) {
                if (enemy.isAlive() && bullet->getX() >= enemy.getX() && bullet->getX() <= enemy.getX() + 30
                    && bullet->getY() <= enemy.getY() + 30 && bullet->getY() >= enemy.getY()) {
                    enemy.die();
                    explosions.emplace_back(enemy.getX(), enemy.getY());
                    bullet->deactivate();
                    score += 10;
                    break;
                }
            }
        }

        if (bullet->isFromEnemy()) {
            if (bullet->getX() >= player->getX() && bullet->getX() <= player->getX() + 40
                && bullet->getY() >= player->getY() && bullet->getY() <= player->getY() + 20) {
                --lives;
                bullet->deactivate();
                if (lives <= 0) isRunning = false;
                break;
            }
        }
    }
}

void Game::deleteInactiveBullets() {
    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(), [](Bullet* b) {
            if (!b->isActive()) {
                delete b;
                return true;
            }
            return false;
        }),
        bullets.end()
    );
}