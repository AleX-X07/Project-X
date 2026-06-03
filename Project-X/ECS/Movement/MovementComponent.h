#pragma once

#include "../Object.h"

class movementsComponent : public Component
{
private:
    float speed;
    sf::Vector2f LevelSize;

public:
    movementsComponent(Object* _owner, float _speed, sf::Vector2f _LevelSize);
    ~movementsComponent() override = default;

    float getSpeed();
    void setSpeed(float newSpeed);

    void left(float deltaTime);
    void right(float deltaTime);
    void up(float deltaTime);
    void down(float deltaTime);
};