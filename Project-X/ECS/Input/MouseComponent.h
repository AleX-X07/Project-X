#pragma once

#include "../Object.h"
#include "../../Pattern/GamepadType.h"

class GameEngine;

class MouseComponent : public Component
{
public:
    AxisMapping mapping;
    
public:
    MouseComponent(Object* owner);
    ~MouseComponent() override = default;
    
    void update(float dt) override;
    
    sf::Vector2i getMousePosition();
    bool keepClick();
    bool clicked();
    
    bool isClick();
};