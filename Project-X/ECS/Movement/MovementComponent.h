#pragma once

#include "../Object.h"
#include "../../Tool/Globals.h"

class MovementsComponent : public Component
{
private:
    float speed;

public:
    float VelocityX = 0;
    float VelocityY = 0;
    
public:
    MovementsComponent(Object* _owner, float _speed);
    ~MovementsComponent() override = default;

    float getSpeed();
    void setSpeed(float newSpeed);

    void left(float deltaTime);
    void right(float deltaTime);
    void up(float deltaTime);
    void down(float deltaTime);
    
    void NoneHori();
    void NoneVert();
};