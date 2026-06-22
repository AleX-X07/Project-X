#pragma once
#include "../../Object.h"

class GameEngine;

class GoldContainer : public Component
{
public:
    int gold = 0;
    
public:
    GoldContainer(Object* _owner, int _gold, float luck);
    ~GoldContainer() override = default;

    int getGold();
};