#pragma once
#include "../../Object.h"

class GameEngine;

class ExpManager : public Component
{
public:
    int Exp = 0;
    
public:
    ExpManager(Object* _owner);
    ~ExpManager() override = default;

    void update(float deltaTime) override;
    
    void setExp(int _exp);
    int getExp();
};