#pragma once
#include "../../Object.h"

#include "../HealthComponent.h"
#include "../Experience/ExpManager.h"

#include "../CameraComponent.h"

class GameEngine;

class DebugHudComp : public Component
{
public:
    sf::Text* Hp;
    sf::Text* Exp;
    
    sf::Font font;
    
public:
    DebugHudComp(Object* _owner);
    ~DebugHudComp() override;

    void update(float deltaTime) override;
    void render() override;
};