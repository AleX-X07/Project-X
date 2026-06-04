#pragma once
#include "../Object.h"

class GameEngine;

class CrossHairComponent : public Component
{
public:
    Object* Cross;
    
    sf::Vector2f storedLoc;
    
    float Xjoystick;
    float Yjoystick;

public:
    CrossHairComponent(Object* _owner);
    ~CrossHairComponent() override;
    
    void update(float deltaTime) override;
    void render() override;
};