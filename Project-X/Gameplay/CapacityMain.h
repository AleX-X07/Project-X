#pragma once
#include <SFML/Graphics.hpp>
#include "../ECS/Object.h"

class GameEngine;

class CapacityMain : public Component {
public:
    sf::RectangleShape HUDrect;
    sf::Texture HUDtx;
    
    bool CanUse;
    float CoolDown;
    float CoolDownActualTime = 0;
public:
    CapacityMain(Object* _owner);
    ~CapacityMain();
    
    virtual void update(float dt);
    virtual void render();
    virtual void activate();
    
    void renderHUD();
};
