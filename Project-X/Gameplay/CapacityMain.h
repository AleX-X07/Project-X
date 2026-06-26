#pragma once
#include <SFML/Graphics.hpp>
#include "../ECS/Object.h"

#include <functional>
#include <vector>
#include <string>

struct UpgradeStat {
    std::string label;
    std::function<void()> apply;
    std::function<std::string()> preview;
};

class GameEngine;

class CapacityMain : public Component {
public:
    int level = 0;
    int maxLevel = 5;
    
    int LinkButton;

public:
    
    sf::RectangleShape HUDrect;
    sf::RectangleShape HUDlevel;
    
    sf::Texture HUDtx;
    sf::Texture HUDtxLv;
    
    bool CanUse;
    float CoolDown;
    float CoolDownActualTime = 0;
public:
    CapacityMain(Object* _owner, int Button);
    ~CapacityMain();
    
    virtual void update(float dt);
    virtual void render();
    virtual void activate();
    
    virtual void levelUp();
    void renderHUD();
};
