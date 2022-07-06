//
// Created by emir on 06.07.22.
//
#include "SFML/Graphics.hpp"

#ifndef PONG_BAT_H
#define PONG_BAT_H


class Bat {
public:
    Bat(float startX, float startY);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    void moveLeft();

    void moveRight();

    void stopLeft();

    void stopRight();

    void update(sf::Time dt);

private:
    sf::Vector2f mPosition;
    sf::RectangleShape mShape;

    float mSpeed = 1000.f;
    bool mMovingLeft = false;
    bool mMovingRight = false;
};


#endif //PONG_BAT_H
