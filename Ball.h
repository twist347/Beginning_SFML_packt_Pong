//
// Created by emir on 06.07.22.
//
#include <SFML/Graphics.hpp>

#ifndef PONG_BALL_H
#define PONG_BALL_H


class Ball {
public:
    Ball(float startX, float startY);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    float getXVelocity();

    void reboundSides();

    void reboundBatOrTop();

    void reboundBottom();

    void update(sf::Time dt);

private:
    sf::Vector2f mPosition;
    sf::RectangleShape mShape;

    float mSpeed = 1500.f;
    float mDx = .2f;
    float mDy = .2f;
};


#endif //PONG_BALL_H
