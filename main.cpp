#include <iostream>
#include "SFML/Graphics.hpp"
#include "Bat.h"
#include "Ball.h"
#include <sstream>

static int const WIDTH = 1920;
static int const HEIGHT = 1080;

int main() {
    sf::VideoMode vm(WIDTH, HEIGHT);
    sf::RenderWindow window(vm, "Pong");
//    window.setVerticalSyncEnabled(true);

    int score = 0;
    int lives = 3;

    Bat bat(WIDTH / 2, HEIGHT - 20);
    Ball ball(WIDTH / 2, 0);

    sf::Font font;
    font.loadFromFile("../fonts/arialmt.ttf");

    sf::Text hud;
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(sf::Color::White);
    hud.setPosition(20, 20);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            bat.moveLeft();
        } else {
            bat.stopLeft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            bat.moveRight();
        } else {
            bat.stopRight();
        }

        auto dt = clock.restart();

        bat.update(dt);
        ball.update(dt);

        std::stringstream ss;
        ss << "Score: " << score << " Lives: " << lives;
        hud.setString(ss.str());

        if (ball.getPosition().top > window.getSize().y) {
            ball.reboundBottom();
            --lives;
            if (lives < 1) {
                score = 0;
                lives = 3;
            }
        }

        if (ball.getPosition().top < 0) {
            ball.reboundBatOrTop();
            ++score;
        }

        if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > window.getSize().x) {
            ball.reboundSides();
        }

        if (ball.getPosition().intersects(bat.getPosition())) {
            ball.reboundBatOrTop();
        }

        window.clear();

        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());

        window.display();
    }
}
