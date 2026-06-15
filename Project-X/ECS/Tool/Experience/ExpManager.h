#pragma once
#include "../../Object.h"

class GameEngine;

class ExpManager : public Component
{
public:
    sf::RectangleShape rect;
    sf::RectangleShape bar;
    
    float Exp = 0;
    
public:
    ExpManager(Object* _owner);
    ~ExpManager() override = default;

    void update(float deltaTime) override;
    void render() override;
    
    void setExp(int _exp);
    float getExp();
};