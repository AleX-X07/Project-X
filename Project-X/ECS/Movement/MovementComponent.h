#pragma once

#include "../Object.h"

class movementsComponent : public Component
{
private:
    float speed;

public:
    movementsComponent(Object* _owner, float _speed);
    ~movementsComponent() override = default;

    float getSpeed();
    void setSpeed(float newSpeed);

    void left(float deltaTime);
    void right(float deltaTime);
    void up(float deltaTime);
    void down(float deltaTime);
};