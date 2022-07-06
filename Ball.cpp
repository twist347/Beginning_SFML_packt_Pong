//
// Created by emir on 06.07.22.
//

#include "Ball.h"

Ball::Ball(float startX, float startY) {
    mPosition.x = startX;
    mPosition.y = startY;

    mShape.setSize({10, 10});
    mShape.setPosition(mPosition);
}

sf::FloatRect Ball::getPosition() {
    return mShape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape() {
    return mShape;
}

float Ball::getXVelocity() {
    return mDx;
}

void Ball::reboundSides() {
    mDx = -mDx;
}

void Ball::reboundBatOrTop() {
    mDy = -mDy;
}

void Ball::reboundBottom() {
    mPosition.x = 500;
    mPosition.y = 0;
    mDy = -mDy;
}

void Ball::update(sf::Time dt) {
    mPosition.x += mDx * mSpeed * dt.asSeconds();
    mPosition.y += mDy * mSpeed * dt.asSeconds();

    mShape.setPosition(mPosition);
}






