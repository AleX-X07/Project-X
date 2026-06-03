#pragma once
#include "../../Object.h"

class GameEngine;

class GrenadeBullet : public Component
{
public:
    float radius;
    
public:
    GrenadeBullet(Object* _owner);
    ~GrenadeBullet() override = default;

    virtual Object* CreateBullet(float angle);
};