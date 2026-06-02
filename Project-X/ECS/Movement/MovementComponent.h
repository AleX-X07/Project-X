#pragma once

#include "../Object.h"

class MovementsComponent : public Component
{
private:
    float speed;

public:
    MovementsComponent(Object* _owner, float _speed);
    ~MovementsComponent() override = default;

    float getSpeed();
    void setSpeed(float newSpeed);

    void left(float deltaTime);
    void right(float deltaTime);
    void up(float deltaTime);
    void down(float deltaTime);
};